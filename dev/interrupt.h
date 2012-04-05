/*
 * intterrupt.h
 *
 *  Created on: Mar 28, 2012
 *      Author: fulong
 */

#ifndef INTTERRUPT_H_
#define INTTERRUPT_H_

#include	"../task_configure/includes.h"
#include "../s3c2440/s3c2440.h"
#include "../dev/uart.h"

extern void irq_handle(void);
extern void timer0_irq(void);
extern void uart0_irq(void);
extern void irq_init(void);

#endif /* INTTERRUPT_H_ */
