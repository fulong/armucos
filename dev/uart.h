/*
 * =====================================================================================
 *
 *       Filename:  uart.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10:00:57 AM  Mar 31, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef UART_H_
#define UART_H_
#include "../task_configure/includes.h"
#include "../s3c2440/s3c2440.h"
#	define TXD0						2		//设为TXD口
#	define RXD0						2		//设为RXD口

#	define STOP_BIT					(0 << 2)//有一位停止位
#	define DATA_BIT					(3 << 0)//有八位数据位

#	define TX_INT_TYPE				(0 << 9)//中断请求类型 0：脉冲，1：边沿
#	define RX_INT_TYPE				(0 << 8)//中断请求类型 0：脉冲，1：边沿
#	define R_TIME_OUT				(0 << 7)//读超时中断请求开关 0：关，1：开
#	define R_ERROR_INT				(0 << 6)//错误，例如，break信号，帧错误，奇偶错误，等中断请求开关 0：关，1：开
#	define SEND_SIGNAL				(0 << 4)//0:正常传输，1：break信号传输
#	define TRANSMIT_MODE			(1 << 2)//中断或查询方式
#	define RRECEIVE_MODE			(1 << 0)//中断或查询方式

#	define TX_FIFO_TRIGGER			(0 << 6)//uart的FIFO发送的触发阀值
#	define RX_FIFO_TRIGGER			(0 << 4)//uart的FIFO发送的触发阀值
#	define TX_FIFO_RESET			(0 << 2)//uart的TXFIFO清空
#	define RX_FIFO_RESET			(0 << 1)//uart的RXFIFO清空
#	define FIFO_ENABLE				(0 << 1)//uart的FIFO发送的触发阀值



#	define UFCON_SET				(FIFO_ENABLE+RX_FIFO_RESET+TX_FIFO_RESET+RX_FIFO_TRIGGER+TX_FIFO_TRIGGER)
#	define UCON_SET					(RRECEIVE_MODE+TRANSMIT_MODE+SEND_SIGNAL+R_ERROR_INT+\
									R_TIME_OUT+RX_INT_TYPE+TX_INT_TYPE)
#	define ULCON0_SET				(STOP_BIT+DATA_BIT)
#	define UART0_PORT_SET()			\
			GPHCON &= ~((3 << 4)+(3 << 6));\
			GPHCON |= ((TXD0 << 4)+(RXD0 << 6));\
			GPHUP  = 0x00;

extern void uart0_init(INT32U baudrate);
extern void uart0_putc();
INT8U uart_buffer[64];			//uart缓冲池
typedef struct {
	INT8U queue_head;
	INT8U queue_tail;
}UART_BUF_COUNTER;				//缓冲池的计数器
UART_BUF_COUNTER buf_counter;

#	define UART_NO_ERROR		0

#endif /* UART_H_ */
