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
#include "app_project/testtask.h"
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
#ifdef __DEBUG__
	INT32U i;
	INT8U debug_num[] = {'0','x','0','0','0','0','0','0','0','0',0};
	putc_string("\n\r");
	putc_string("now be into the ucos");
#endif

#ifdef __DEBUG__
	putc_string("\n\r");
	putc_string("OSInit() enter");
#endif
	OSInit();

#ifdef __DEBUG__
	putc_string("\n\r");
	putc_string("OSStart() enter");
#endif
OSTaskCreate(TestTask,(void *)0,&TestTaskStk[99],0);

	OSStart();

while(1);

	return 0;
}

