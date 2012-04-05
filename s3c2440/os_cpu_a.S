.globl OSStartHighRdy
OSStartHighRdy:
	ldr r4,=OSTCBCur	/*得到当前任务TCB地址*/
	ldr r5,=OSTCBHighRdy /*得到最高优先级任务TCB地址*/

	ldr r5,[r5]		//获得堆栈指针
	ldr sp,[r5]		//转移到新的堆栈中

	str r5,[r4]		//设置新的当前任务TCB地址
	ldmfd sp!,{r4}
	msr spsr,r4
	ldmfd sp!,{r4}	//处于SVC32mode
	msr cpsr,r4
	ldmfd sp!,{r0-r12,lr,pc}//运行新的任务
