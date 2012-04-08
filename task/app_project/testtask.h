/*
 * =====================================================================================
 *
 *       Filename:  testtask.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11:48:08 PM  Apr 7, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef TESTTASK_H_
#define TESTTASK_H_

#include "../debug.h"
OS_STK	TestTaskStk[100];
extern void TestTask(void *pdata);

#endif /* TESTTASK_H_ */
