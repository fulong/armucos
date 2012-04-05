/*
 * =====================================================================================
 *
 *       Filename:  uart.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10:00:35 AM  Mar 31, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "uart.h"

#	define UART_CLK					PCLK
#	define UART_BRD(UART_BAUD_RATE)	(UART_CLK / ((UART_BAUD_RATE) * 16)-1)
void uart0_init(INT32U baudrate)
{
	UART0_PORT_SET()
	ULCON0 = ULCON0_SET;
	UCON0 = UCON_SET;
	UFCON0 = UFCON_SET;
	UMCON0 = 0;   			/*关闭流控*/
	UBRDIV0 = UART_BRD(baudrate);
	buf_counter.queue_head = 0;
	buf_counter.queue_tail = 0;
}
//操作读缓冲区的
void uart0_putc(){

		/*		判断buf_counter队列是否为空*/
		while(buf_counter.queue_head != buf_counter.queue_tail)
			{
			if(buf_counter.queue_head == 64)
			{/*当队列头到界限时，将会折回*/
				buf_counter.queue_head = 0;
			}
			UTXH0 = uart_buffer[buf_counter.queue_head];
			while(!(UTRSTAT0 & (1<<2)));
			buf_counter.queue_head++;
			}
}

