//设置向量表
#include "memory.h"
.arm
.globl _start
_start: b       start_code
        ldr     pc, _undefined_instruction
        ldr     pc, _software_interrupt
        ldr     pc, _prefetch_abort
        ldr     pc, _data_abort
        ldr     pc, _not_used
        ldr     pc, _irq
        ldr     pc, _fiq

_undefined_instruction: .word undefined_instruction
_software_interrupt:    .word software_interrupt
_prefetch_abort:        .word prefetch_abort
_data_abort:            .word data_abort
_not_used:              .word not_used
_irq:                   .word irq
_fiq:                   .word fiq

        .balignl 16,0xdeadbeef


start_code:
        /*
         * set the cpu to SVC32 mode
         */
        mrs     r0, cpsr
        bic     r0, r0, #0x1f
        orr     r0, r0, #0xd3
        msr     cpsr, r0

#  define pWTCON        0x53000000
#  define INTMSK        0x4A000008      /* Interrupt-Controller base addresses */
#  define INTSUBMSK     0x4A00001C
//#  define CLKDIVN       0x4C000014      /* clock divisor register */


        ldr     r0, =pWTCON
        mov     r1, #0x0
        str     r1, [r0]

        /*
         * mask all IRQs by setting all bits in the INTMR - default
         */
        mov     r1, #0xffffffff
        ldr     r0, =INTMSK
        str     r1, [r0]

        ldr     r1, =0x3ff
        ldr     r0, =INTSUBMSK
        str     r1, [r0]

		msr cpsr_c,#0xd2
		ldr sp,=3072
		msr cpsr_c,#0x5f
		ldr 	sp, =1024*4
		bl clock_init
		bl sdram_init
		bl copy_steppingstone_to_sdram
		ldr pc,=on_sdram
on_sdram:
		ldr sp,=0x34000000
		bl main
halt:
		bl halt

copy_steppingstone_to_sdram:
		mov r1,#0
		ldr r2,=SDRAM_BASE
		mov r3,#4096 @steppingstone的大小
1:
		ldr r4,[r1],#4
		str r4,[r2],#4
		cmp r1,r3
		bne 1b
		mov pc,lr
sdram_init:
		mov r1,#MEM_CTL_BASE
		adrl r2,mem_cfg_val
		add r3,r1,#52
1:
		ldr r4,[r2],#4
		str r4,[r1],#4
		cmp r1,r3
		bne 1b
		mov pc,lr
		.align 5
mem_cfg_val:
		.long BWSCON_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONx_SET
		.long BANKCONn_SET
		.long BANKCONn_SET
		.long REFRESH_SET
		.long BANKSIZE_SET
		.long MRSRBx_SET
		.long MRSRBx_SET
/*
 * exception handlers
 */
        .align  5
undefined_instruction:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_undefined_instruction
		bl undefined_instruction
        .align  5
software_interrupt:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_software_interrupt
		bl software_interrupt
        .align  5
prefetch_abort:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_prefetch_abort
		bl prefetch_abort

        .align  5
data_abort:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_data_abort
		bl data_abort
        .align  5
not_used:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_not_used
		bl not_used

#ifdef CONFIG_USE_IRQ

        .align  5
irq:
//        get_irq_stack
//        irq_save_user_regs
//        bl      do_irq
//        irq_restore_user_regs
		bl irq
        .align  5
fiq:
//        get_fiq_stack
        /* someone ought to write a more effiction fiq_save_user_regs */
//        irq_save_user_regs
//        bl      do_fiq
//        irq_restore_user_regs
		bl fiq
#else

        .align  5
irq:
//        get_bad_stack
		sub lr,lr,#4
//        bad_save_user_regs
		stmdb sp!,{r0-r12,lr}
//        bl      do_irq
		bl irq_handle
		ldmia sp!,{r0-r12,pc}^
        .align  5
fiq:
//        get_bad_stack
//        bad_save_user_regs
//        bl      do_fiq
		bl fiq
#endif
