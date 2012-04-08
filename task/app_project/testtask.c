/*
 * =====================================================================================
 *
 *       Filename:  testtask.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11:47:41 PM  Apr 7, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "testtask.h"

void TestTask(void *pdata)
{
	while(1)
		{
		putc_string("now ,it is in the TestTask Fundation\r\n");
		OSTimeDly(1);

		}
}

