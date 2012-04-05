/*
 * led.c
 *
 *  Created on: Mar 26, 2012
 *      Author: fulong
 */




#include "led.h"

#ifndef __DEBUG__
#define GPB_OUTPUT(NUM) GPBCON &= ~(3 << ((2*NUM)));GPBCON |= (1 << ((2*NUM)));
#define GPB_UP() GPBUP &= 0x0;
#define GPB_DAT_OFF(NUM) GPBDAT |= (1 << (NUM));
#define GPB_DAT_ON(NUM) GPBDAT &= ~(1 << (NUM));
#endif
void led_init(void)
{
	GPB_OUTPUT(5);
	GPB_OUTPUT(6);
	GPB_OUTPUT(7);
	GPB_OUTPUT(8);
	GPB_UP()
	GPB_DAT_OFF(5)
	GPB_DAT_OFF(6)
	GPB_DAT_OFF(7)
	GPB_DAT_OFF(8)
//	GPB_OUTPUT(0)
//	GPB_DAT_ON(0)
}

void led_on(INT8U NUM)
{
	GPB_DAT_ON(NUM);
}

void led_off(INT8U NUM)
{
	GPB_DAT_OFF(NUM);
}
