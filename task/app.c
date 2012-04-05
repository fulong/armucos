/*
 * =====================================================================================
 *
 *       Filename:  app.c
 *
 *    Description:  some_my_testapp
 *
 *        Version:  1.0
 *        Created:  03/26/2012 12:45:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fulong (), fulong.mo@gmail.com
 *   Organization:  gdqy
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
//BOOLEAN flag = 0;

INT32S main(void)
{
	INT8U *buf;
	buf = (INT8U *)0x30030000;
	INT8U p_char[13]={'0','x','0','0','0','0','0','0','0','0','\r','\n',0};
	INT32U i;
	uart0_init(115200);
	led_init();
//	timer0_init();
	irq_init();

	nand_init();
	nand_read(buf,0,12);
for(i=0;i<12;i++){
	num_to_char(buf[i],p_char);
//	p_char[0] = (buf[0]%10)+'0';
	putc_string(p_char);

}

	return 0;
}
