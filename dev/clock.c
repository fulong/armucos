#include "clock.h"
/*如果同时配置UPLL时，要先设置UPLL，并相隔7个NOP*/

/****************************************************
 * 2位		1位
 * HDIVN	PDIVN	HCLK3_HALF/HCLK4_HALF	F:H:P
 * 0		0		-						1:1:1
 * 0		1		-						1:1:2
 * 1		0		-						1:2:2
 * 1		1		-						1:2:4
 * 3		0		0/0						1:3:3
 * 3		1		0/0						1:3:6
 * 3		0		1/0						1:6:6
 * 3		1		1/0						1:6:12
 * 2		0		0/0						1:4:4
 * 2		1		0/0						1:4:8
 * 2		0		0/1						1:8:8
 * 2 		1		0/1						1:8:16
 * HCLK3_HALF/HCLK4_HALF是CAMDIVN寄存器的8，9位
 */


/*
 * Timer input timer frequency = PCLK / (Prescaler value + 1)/{divider value}
 * 								         TCFG0的前16位		   TCFG1前20位，每4位为一组
 * 								         每八位一个分频器		   值0为2 1为4
 * 								         timer0-1用分频器0	   值2为8 3为16
 * 								         timer2-4用分频器1	   8>值>3 供应时钟为外时钟
 *
 * */

#	define Prescaler0			124 //timer0和1用
#	define Prescaler1			124 << 8/*还没有用到，timer2和3，4用*/
/* divno:						tnum
 * 			0----2分频			0-----代表第0个timer
 * 			1----4分频			如此类推
 * 			2----8分频			最多不超过4
 * 			3----16分频
 * 			8>divno>3-----外部时钟
 */
#	define set_divider(divno,TNUM)	\
		TCFG1 &= ~(0xF << (4*(TNUM)));\
		TCFG1 |= (divno)<<(4*(TNUM));
#	define timer0_en				1		//启动定时器
#	define timer0_dead_en			0		//死区允许
#	define timer0_outinver_en		0		//TOUT0 翻转
#	define update_en			1		//更新TCNTB0 TCMPB0
#	define timer0_auto_en			1		//自动加载
#	define timer0_start				\
		TCON &= ~(0X1f);\
		TCON |= timer0_en + \
				(timer0_outinver_en << 2) + \
				(timer0_auto_en << 3) + \
				(timer0_dead_en << 4);
#	define timer0_close				TCON &= ~(0X1f);

void timer0_init(void)
{
	TCFG0 &= ~(0xFF) ;
	TCFG0 |= Prescaler0 ;//124
	set_divider(2,0)
	TCNTB0 = 50000; //1S 中断一次
	TCON |= update_en<<1;	//启动定时器时自动加载TCNTB0到TCNT0，当下次使用TCON时，这位会自动清零

	timer0_start
}
#	define timer4_en				(1 << 20)
#	define timer4_auto_en			(1 << 22)

#	define timer4_start				\
		TCON &= ~(0X7 << 20);\
		TCON |= (timer4_en + \
				timer4_auto_en);

void timer4_init(void)
{
	TCFG0 &= ~(0xFF << 8) ;
	TCFG0 |= Prescaler1 ;//124
	set_divider(2,4)
	TCNTB4 = 50000; //1S 中断一次
	TCON |= update_en << 21;	//启动定时器时自动加载TCNTB4到TCNT4，当下次使用TCON时，这位会自动清零

	timer4_start
}
