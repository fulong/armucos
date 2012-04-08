.globl OSStartHighRdy
.globl OSIntCtxSw

.globl _OS_TASK_SW
OSStartHighRdy:
	ldr r4,=OSTCBCur	/*得到当前任务TCB地址*/
	ldr r5,=OSTCBHighRdy /*得到最高优先级任务TCB地址*/

	ldr r5,[r5]		//获得堆栈指针
	ldr sp,[r5]		//转移到新的堆栈中

	str r5,[r4]		//设置新的当前任务TCB地址
	ldmia sp!,{r4}
	msr spsr,r4
	ldmia sp!,{r4}	//处于SVC32mode
	msr cpsr,r4
	ldmia sp!,{r0-r12,lr,pc}//运行新的任务

OSIntCtxSw:
	add r7,sp,#16	//保存寄存器指针
	ldr sp,=3072	//FIQ_STACK or IRQStack
	mrs r1,spsr
	orr r1,r1,#0xC0 //关闭IRQ，FIQ
	msr cpsr_cxsf,r1
	ldr r0,[r7,#52]	//得到FIQ LR指针
	sub r0,r0,#4	//保存任务PC
	stmfd sp!,{r0}
	stmfd sp!,{lr}
	mov lr,r7
	ldmfd lr!,{r0-r12}
	stmfd sp!,{r0-r12}

	mrs r4,cpsr
	bic r4,r4,#0xC0
	stmfd sp!,{r4}
	mrs r4,spsr
	stmfd sp!,{r4}
	ldr r4,=OSPrioCur
	ldr r5,=OSPrioHighRdy
	ldrb r6,[r5]
	strb r6,[r4]

	ldr r4,=OSTCBCur
	ldr r5,[r4]
	str sp,[r5]

	ldr r6,=OSTCBHighRdy
	ldr r6,[r6]
	ldr sp,[r6]

	str r6,[r4]
	ldmfd sp!,{r4}
	msr spsr,r4
	ldmfd sp!,{r4}
	bic r4,r4,#0xC0
	msr cpsr,r4
	ldmfd sp!,{r0-r12,lr,pc}

_OS_TASK_SW:
	stmfd sp!,{lr}
	stmfd sp!,{lr}
	stmfd sp!,{r0-r12}
	mrs r4,cpsr
	stmfd sp!,{r4}
	mrs r4,spsr
	stmfd sp!,{r4}

	ldr r4,=OSPrioCur
	ldr r5,=OSPrioHighRdy
	ldrb r6,[r5]
	strb r6,[r4]

	ldr r4,=OSTCBCur
	ldr r5,[r4]
	str sp,[r5]

	ldr r6,=OSTCBHighRdy
	ldr r6,[r6]
	ldr sp,[r6]

	str r6,[r4]

	ldmia sp!,{r4}
	msr spsr,r4
	ldmia sp!,{r4}
	msr cpsr,r4

	ldmia sp!,{r0-r12,lr,pc}
