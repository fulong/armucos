/*
 * intterrupt.c
 *
 *  Created on: Mar 28, 2012
 *      Author: fulong
 */

#include "interrupt.h"

#ifdef __DEBUG__
#include "../task/led.h"
#endif

/*          INTOFFSET,INTMSK,INTMOD,SRCPND     */
#	define ADC_OFFSET				31
#	define ADC_INT_MSK				(1<<ADC_OFFSET)

#	define RTC_OFFSET				30
#	define RTC_INT_MSK				(1<<RTC_OFFSET)

#	define SPI1_OFFSET				(29)
#	define SPI1_INT_MSK				(1<<SPI1_OFFSET)

#	define UART0_OFFSET				28
#	define UART0_INT_MSK			(1<<28)

#	define IIC_OFFSET				27
#	define IIC_INT_MSK				(1<<IIC_OFFSET)

#	define USBH_OFFSET				26
#	define USBH_INT_MSK				(1<<USBH_OFFSET)

#	define USBD_OFFSET				25
#	define USBD_INT_MSK				(1<<USBD_OFFSET)

#	define NFCON_OFFSET				(24)
#	define NFCON_INT_MSK			(1<<NFCON_OFFSET)

#	define UART1_OFFSET				23
#	define UART1_INT_MSK			(1<<UART1_OFFSET)

#	define SPI0_OFFSET				22
#	define SPI0_INT_MSK				(1<<SPI0_OFFSET)

#	define SDI_OFFSET				21
#	define SDI_INT_MSK				(1<<SDI_OFFSET)

#	define DMA3_OFFSET				20
#	define DMA3_INT_MSK				(1<<DMA3_OFFSET)

#	define DMA2_OFFSET				19
#	define DMA2_INT_MSK				(1<<DMA2_OFFSET)

#	define DMA1_OFFSET				18
#	define DMA1_INT_MSK				(1<<DMA1_OFFSET)

#	define DMA0_OFFSET				17
#	define DMA0_INT_MSK				(1<<DMA0_OFFSET)

#	define LCD_OFFSET				16
#	define LCD_INT_MSK				(1<<LCD_OFFSET)

#	define UART2_OFFSET				15
#	define UART2_INT_MSK			(1<<UART2_OFFSET)

#	define T4_OFFSET				14
#	define T4_INT_MSK				(1<<T4_OFFSET)

#	define T3_OFFSET				13
#	define T3_INT_MSK				(1<<T3_OFFSET)

#	define T2_OFFSET				12
#	define T2_INT_MSK				(1<<T2_OFFSET)

#	define T1_OFFSET				11
#	define T1_INT_MSK				(1<<T1_OFFSET)

#	define T0_OFFSET				10
#	define T0_INT_MSK				(1<<T0_OFFSET)

#	define WDTAC97_OFFSET			9
#	define WDTAC97_INT_MSK			(1<<WDTAC97_OFFSET)

#	define TICK_OFFSET				8
#	define TICK_INT_MSK				(1<<TICK_OFFSET)

#	define nBATTFLT_OFFSET			7
#	define nBATTFLT_INT_MSK			(1<<nBATTFLT_OFFSET)

#	define CAM_OFFSET				6
#	define CAM_INT_MSK				(1<<CAM_OFFSET)

#	define ENT823_OFFSET			5
#	define ENT823_INT_MSK			(1<<ENT823_OFFSET)

#	define ENT47_OFFSET				4
#	define ENT47_INT_MSK			(1<<ENT47_OFFSET)

#	define ENT3_OFFSET				3
#	define ENT3_INT_MSK				(1<<ENT3_OFFSET)

#	define ENT2_OFFSET				2
#	define ENT2_INT_MSK				(1<<ENT2_OFFSET)

#	define ENT1_OFFSET				1
#	define ENT1_INT_MSK				(1<<ENT1_OFFSET)

#	define ENT0_OFFSET				0
#	define ENT0_INT_MSK				(1<<ENT0_OFFSET)

/*          INTOFFSET,INTMSK,INTMOD,SRCPND     */

/*SUBMASK SUBSRCPND*/
/*各位的掩码*/
#	define SUB_RXD0_MSK				(1<<0)
#	define SUB_TXD0_MSK				(1<<1)
#	define SUB_ERR0_MSK				(1<<2)
#	define SUB_RXD1_MSK				(1<<3)
#	define SUB_TXD1_MSK				(1<<4)
#	define SUB_ERR1_MSK				(1<<5)
#	define SUB_RXD2_MSK				(1<<6)
#	define SUB_TXD2_MSK				(1<<7)
#	define SUB_ERR2_MSK				(1<<8)
#	define SUB_TC_MSK				(1<<9)
#	define SUB_ADCS_MSK				(1<<10)
#	define SUB_CAMC_MSK				(1<<11)
#	define SUB_CAMP_MSK				(1<<12)
#	define SUB_WDT_MSK				(1<<13)
#	define SUB_AC97_MSK				(1<<14)
/*SUBMASK SUBSRCPND*/

//#	define TIMER0
//#	define UART0
#	define TIMER4


void irq_init(void)
{
	#ifdef TIMER0
	INTMSK &= (~T0_INT_MSK);
	#endif

	#ifdef TIMER4
	INTMSK &= (~T4_INT_MSK);
	INTMOD = T4_INT_MSK;
	#endif

	#ifdef UART0
	INTMSK &= (~UART0_INT_MSK);
	INTSUBMSK &= (~(SUB_RXD0_MSK));
	#endif


}

void irq_handle(void)
{

	switch (INTOFFSET)
	{
	case T0_OFFSET		:
			{timer0_irq();break;}
	case UART0_OFFSET	:
			{uart0_irq();break;}
	default:break;
	}
}

void timer0_irq(void)
{
	INT32U temp;
    GPBDAT = ~(GPBDAT & (0xf << 5));
    //清中断
    SRCPND = 1 << T0_OFFSET;
    temp = INTPND;
    INTPND = temp;
}

void uart0_irq(void)
{
#define READREADY 1
#define SENDREADY (1 << 2)
	INT32U temp;
    //清中断
    if(UTRSTAT0 & READREADY)
    	{
    		uart_buffer[buf_counter.queue_tail] = URXH0;
    		buf_counter.queue_tail++;
    		if(buf_counter.queue_tail == 64)
    		{/*当队列尾到界限时，将会折回*/
    			buf_counter.queue_tail = 0;
    		}
    	}

    SUBSRCPND = SUB_RXD0_MSK;
    SRCPND = 1 << UART0_OFFSET;
    temp = INTPND;
    INTPND = temp;
}

void fiq_handle(void)
{
	INT32U temp;
    GPBDAT = ~(GPBDAT & (0xf << 5));
    //清中断
    SRCPND = 1 << T4_OFFSET;
    temp = INTPND;
    INTPND = temp;

}
void software_handle(trap_num)
{
	switch(trap_num){
	case 0x80 :	_OS_TASK_SW();
				break;
	default:break;
	}
}
