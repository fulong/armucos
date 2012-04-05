
#include "nand.h"

/*NAND FLASH 命令*/
#	define CMD_READ1				0x00	//读命令的第一个周期
#	define CMD_READ2				0x30	//这两条指令是在CMD_READ1后第二个
#	define CMD_READ_COPY_BACK		0x35	//周期写的，分别对应两个功能
#	define CMD_ID					0x90
#	define CMD_RESET				0xFF
#	define CMD_PAGE_WRITE			0x80	//在CMD_PAGE_WRITE后第二个
#	define CMD_PAGE_WRITE1			0x10	//周期写的，分别对应两个功能
#	define CMD_BLK_ERASE			0x60	//在CMD_PAGE_WRITE后第二个
#	define CMD_BLK_ERASE1			0xD0	//周期写的，分别对应两个功能
#	define CMD_STATUS				0x70
/*NAND FLASH 命令*/
static S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;



/* S3C2440的NAND Flash处理函数 */
static void s3c2440_nand_reset(void);
static void s3c2440_wait_idle(void);
static void s3c2440_nand_select_chip(void);
static void s3c2440_nand_deselect_chip(void);
static void s3c2440_write_cmd(int cmd);
static void s3c2440_write_addr_lp(unsigned int addr);
static unsigned char s3c2440_read_data(void);


/* S3C2440的NAND Flash操作函数 */
/* 复位 */
static void s3c2440_nand_reset(void)
{
    s3c2440_nand_select_chip();
    s3c2440_write_cmd(CMD_RESET);  // ��λ����
    s3c2440_wait_idle();
    s3c2440_nand_deselect_chip();
}

/* 等待NAND Flash就绪 */
static void s3c2440_wait_idle(void)
{
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFSTAT;
    while(!(*p & BUSY));
}

/* 发出片选信号 */
static void s3c2440_nand_select_chip(void)
{
    int i;
    s3c2440nand->NFCONT &= ~(1<<1);
    for(i=0; i<10; i++);    
}

/* 取消片选信号 */
static void s3c2440_nand_deselect_chip(void)
{
    s3c2440nand->NFCONT |= (1<<1);
}

/* 发出命令 */
static void s3c2440_write_cmd(int cmd)
{
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFCMD;
    *p = cmd;
}

/* 发出地址 */
static void s3c2440_write_addr_lp(unsigned int addr)
{
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;
	int col, page;

	col = addr & NAND_BLOCK_MASK_LP;
	page = addr / NAND_SECTOR_SIZE_LP;
	
	*p = col & 0xff;			/* Column Address A0~A7 */
	*p = (col >> 8) & 0x0f; 	/* Column Address A8~A11 */
	*p = page & 0xff;			/* Row Address A12~A19 */
	*p = (page >> 8) & 0xff;	/* Row Address A20~A27 */
	*p = (page >> 16) & 0x03;	/* Row Address A28~A29 */
}


/* 读取数据 */
static unsigned char s3c2440_read_data(void)
{
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFDATA;
    return *p;
}


/* 初始化NAND Flash */
void nand_init(void)
{
#define TACLS   2
#define TWRPH0  2
#define TWRPH1  2


    /* 设置时序 */
        s3c2440nand->NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
        /* 使能NAND Flash控制器, 初始化ECC, 禁止片选 */
        s3c2440nand->NFCONT = (1<<4)|(1<<1)|(1<<0);
    
        /* 使能NAND Flash控制器, 初始化ECC, 禁止片选 */
        s3c2440_nand_reset();
}


/* 读函数 */
void nand_read(unsigned char *buf, unsigned long start_addr, int size)
{
    int i, j;

    if ((start_addr & NAND_BLOCK_MASK_LP) || (size & NAND_BLOCK_MASK_LP)) {
        return ;    /* 地址或长度不对齐 */
    }
    /* 选中芯片 */
    s3c2440_nand_select_chip();

    for(i=start_addr; i < (start_addr + size);) {
    	/* 发出READ0命令 */
      s3c2440_write_cmd(CMD_READ1);

      /* Write Address */
      s3c2440_write_addr_lp(i);

      s3c2440_write_cmd(CMD_READ2);

      s3c2440_wait_idle();

      for(j=0; j < NAND_SECTOR_SIZE_LP; j++, i++) {
          *buf = s3c2440_read_data();
          buf++;
      }
    }

    /* 取消片选信号 */
    s3c2440_nand_deselect_chip();
    
    return ;
}

