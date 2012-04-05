/*
 * nand.h
 *
 *  Created on: Mar 30, 2012
 *      Author: fulong
 */

#ifndef NAND_H_
#define NAND_H_
#include "../task_configure/includes.h"
#include "../s3c2440/s3c2440.h"
#define LARGER_NAND_PAGE

#define GSTATUS1        (*(volatile unsigned int *)0x560000B0)
#define BUSY            1

#define NAND_SECTOR_SIZE_LP    2048
#define NAND_BLOCK_MASK_LP     (NAND_SECTOR_SIZE_LP - 1)
typedef unsigned int S3C24X0_REG32;



/* NAND FLASH (see S3C2440 manual chapter 6, www.100ask.net) */
typedef struct {
    S3C24X0_REG32   NFCONF;
    S3C24X0_REG32   NFCONT;
    S3C24X0_REG32   NFCMD;
    S3C24X0_REG32   NFADDR;
    S3C24X0_REG32   NFDATA;
    S3C24X0_REG32   NFMECCD0;
    S3C24X0_REG32   NFMECCD1;
    S3C24X0_REG32   NFSECCD;
    S3C24X0_REG32   NFSTAT;
    S3C24X0_REG32   NFESTAT0;
    S3C24X0_REG32   NFESTAT1;
    S3C24X0_REG32   NFMECC0;
    S3C24X0_REG32   NFMECC1;
    S3C24X0_REG32   NFSECC;
    S3C24X0_REG32   NFSBLK;
    S3C24X0_REG32   NFEBLK;
} S3C2440_NAND;



//static S3C2410_NAND * s3c2410nand = (S3C2410_NAND *)0x4e000000;

extern void nand_init(void);
extern void nand_read(unsigned char *buf, unsigned long start_addr, int size);


#endif /* NAND_H_ */
