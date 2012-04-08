/*
 * =====================================================================================
 *
 *       Filename:  debug.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  6:07:34 PM  Apr 1, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "debug.h"
#ifdef	__DEBUG__


void putc_string(char * str){
	size_t i ,k;
	i = strlen(str);
	for(k = 0;k < i;k++)
	{
		put_char(*(str+k))
	}

}


INT8U num_to_char(INT32U num,INT8U * display_num)
{
	INT8U num_map[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	INT32U i;

	for(i=9;i>1;i--)
	{
		*(display_num+i) = num_map[num % 16];
		num /= 16;
	}

	return 0;
}



#endif
