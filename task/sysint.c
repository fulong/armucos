/*
 * =====================================================================================
 *
 *       Filename:  sysint.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  3:02:10 PM  Apr 7, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "led.h"
#include "../dev/uart.h"
#include "../dev/clock.h"
#include "../dev/interrupt.h"
#include "../dev/nand.h"
#ifdef __DEBUG__
#include "debug.h"
#endif

INT32S _main(void)
{
	led_init();
	uart0_init(115200);
#ifdef __DEBUG__
	putc_string("\n\r");
	putc_string("intial sdram data have done!\n\r");
	putc_string("intial uart0 setting have done!\n\r");
#endif
	irq_init();
#ifdef __DEBUG__
	putc_string("\n\r");
	putc_string("intial irq  have done!\n\r");
	putc_string("this only initializes timer4!\n\r");
	putc_string("and take timer4 into fiq mode!\n\r");
#endif
	timer4_init();
#ifdef __DEBUG__
	putc_string("\n\r");
	putc_string("enable timer4!and evry step in a second\n\r");

	putc_string("\n\r");
	putc_string("now go into the ucos");

#endif

	return 0;
}




