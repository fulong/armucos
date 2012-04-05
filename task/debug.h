/*
 * =====================================================================================
 *
 *       Filename:  debug.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  6:08:39 PM  Apr 1, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef DEBUG_H_
#define DEBUG_H_
#include "../task_configure/includes.h"
#include "../dev/uart.h"



extern void putc_string(const char * str);
INT8U num_to_char(INT32U num,INT8U * display_num);


#endif /* DEBUG_H_ */
