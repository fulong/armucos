#ifndef __LED_H__
#define __LED_H__
#include "../task_configure/includes.h"
#include "../s3c2440/s3c2440.h"

extern void led_init(void);
extern void led_on(INT8U NUM);
extern void led_off(INT8U NUM);

#ifdef __DEBUG__
#define GPB_OUTPUT(NUM) GPBCON &= ~(3 << ((2*NUM)));GPBCON |= (1 << ((2*NUM)));
#define GPB_UP() GPBUP &= 0x0;
#define GPB_DAT_OFF(NUM) GPBDAT |= (1 << (NUM));
#define GPB_DAT_ON(NUM) GPBDAT &= ~(1 << (NUM));
#endif
#endif
