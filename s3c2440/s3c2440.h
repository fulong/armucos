#ifndef __S3C2440_H__
#define __S3C2440_H__
/* **********************************************
 * GPIO口操作相关的寄存器
 * *********************************************/
#	define GPBCON 			(*(volatile INT32U*)0X56000010)
#	define GPBDAT 			(*(volatile INT32U*)0X56000014)
#	define GPBUP			(*(volatile INT32U*)0X56000018)
//跟NAND有关
#	define GPACON 			(*(volatile INT32U*)0X56000000)
/*[17...22]为0时为输出口，不为0时为nand falsh控制口，为别代表为\
CLE,ALE,nFWE,nFRE,nRSTOUT,nFCE*/
#	define GPADAT 			(*(volatile INT32U*)0X56000004)
//跟NAND有关
/*跟uart有关*/
#	define GPHCON 			(*(volatile INT32U*)0X56000070)
#	define GPHDAT 			(*(volatile INT32U*)0X56000074)
#	define GPHUP			(*(volatile INT32U*)0X56000078)
#	define ULCON0			(*(volatile INT32U*)0X50000000)
#	define UCON0			(*(volatile INT32U*)0X50000004)
#	define UFCON0			(*(volatile INT32U*)0X50000008)
#	define UMCON0			(*(volatile INT32U*)0X5000000C)
#	define UTRSTAT0			(*(volatile INT32U*)0X50000010)
#	define UERSTAT0			(*(volatile INT32U*)0X50000014)
#	define UFSTAT0			(*(volatile INT32U*)0X50000018)
#	define UMSTAT0			(*(volatile INT32U*)0X5000001C)
#	define UTXH0			(*(volatile INT8U*)0X50000020)
#	define URXH0			(*(volatile INT8U*)0X50000024)
#	define UBRDIV0			(*(volatile INT32U*)0X50000028)


/*跟uart有关*/

/*************************************************
 *
 * 时钟相关
 *
 ************************************************/
# 	define pWTCON        	(*(volatile INT32U*)0x53000000)
# 	define CLKDIVN       	(*(volatile INT32U*)0x4C000014)      /* clock divisor register */
#	define MPLLCON			(*(volatile INT32U*)0x4C000004)
#	define UPLLCON			(*(volatile INT32U*)0x4C000008)
#	define CAMDIVN			(*(volatile INT32U*)0x4C000018)
/*
 *
 * 与timer有关
 *
 * */
#	define TCFG0			(*(volatile INT32U*)0x51000000)
#	define TCFG1			(*(volatile INT32U*)0x51000004)
#	define TCON				(*(volatile INT32U*)0x51000008)
#	define TCNTB0			(*(volatile INT32U*)0x5100000C)
#	define TCMPB0			(*(volatile INT32U*)0x51000010)
#	define TCNTO0			(*(volatile INT32U*)0x51000014)
#	define TCNTB1			(*(volatile INT32U*)0x51000018)
#	define TCMPB1			(*(volatile INT32U*)0x5100001C)
#	define TCNTO1			(*(volatile INT32U*)0x51000020)
#	define TCNTB2			(*(volatile INT32U*)0x51000024)
#	define TCMPB2			(*(volatile INT32U*)0x51000028)
#	define TCNTO2			(*(volatile INT32U*)0x5100002C)
#	define TCNTO3			(*(volatile INT32U*)0x51000030)
#	define TCNTB3			(*(volatile INT32U*)0x51000034)
#	define TCMPB3			(*(volatile INT32U*)0x51000038)
#	define TCMPB4			(*(volatile INT32U*)0x5100003C)
#	define TCNTO4			(*(volatile INT32U*)0x51000040)
#	define TCNTB4			(*(volatile INT32U*)0x51000044)



/************************************************
 *
 * 中断相关
 *
 */
#  	define INTMSK        	(*(volatile INT32U*)0x4A000008)      /* Interrupt-Controller base addresses */
#  	define INTSUBMSK     	(*(volatile INT32U*)0x4A00001C)
#	define SRCPND			(*(volatile INT32U*)0x4A000000)
#	define INTMOD			(*(volatile INT32U*)0x4A000004)
#	define PRIORITY			(*(volatile INT32U*)0x4A00000C)
#	define INTPND			(*(volatile INT32U*)0x4A000010)
#	define INTOFFSET		(*(volatile INT32U*)0x4A000014)
#  	define SUBSRCPND     	(*(volatile INT32U*)0x4A000018)

/************************************************
 *
 *  SDRAM存储器相关
 *
 */
#  	define BWSCON     		(*(volatile INT32U*)0x48000000)
#	define BANKCON0			(*(volatile INT32U*)0x48000004)
#	define BANKCON1			(*(volatile INT32U*)0x48000008)
#	define BANKCON2			(*(volatile INT32U*)0x4800000C)
#	define BANKCON3			(*(volatile INT32U*)0x48000010)
#	define BANKCON4			(*(volatile INT32U*)0x48000014)
#	define BANKCON5			(*(volatile INT32U*)0x48000018)
#	define BANKCON6			(*(volatile INT32U*)0x4800001C)
#	define BANKCON7			(*(volatile INT32U*)0x48000020)
#	define REFRESH			(*(volatile INT32U*)0x48000024)
#	define BANKSIZE			(*(volatile INT32U*)0x48000028)
#	define MRSRB6			(*(volatile INT32U*)0x4800002C)
#	define MRSRB7			(*(volatile INT32U*)0x48000030)


#endif
