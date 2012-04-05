include var.mk
compiled := source.compiled start_code.compiled task.compiled \
			 dev.compiled s3c2440.compiled lib.compiled
all:	arm_ucos.bin 
#######################################################
arm_ucos.bin: ${compiled}
	@make -C output

	${OBJCOPY} ${OBJCOPY_FLAGS} ${elf_output_dir}arm_ucos.elf $@
	${OBJDUMP} ${OBJDUMP_FLAGS} ${elf_output_dir}arm_ucos.elf > ${elf_output_dir}arm_ucos.dis

#######################################################
source.compiled:${src_dir}*.c ${src_dir}*.h
	@make -C ${src_dir}
	@${RM} $@
	@touch $@
#######################################################
start_code.compiled: ./start_code/*.S  ./start_code/*.h
	@make -C start_code
	@${RM} $@
	@touch $@
#######################################################
task.compiled: ./task/*.c ./task/*.h
	@make -C task
	@${RM} $@
	@touch $@
#######################################################
dev.compiled: ./dev/*.c ./dev/*.h
	@make -C dev
	@${RM} $@
	@touch $@
#######################################################
s3c2440.compiled : ./s3c2440/*.c ./s3c2440/*.h ./s3c2440/*.S
	@make -C s3c2440
	@${RM} $@
	@touch $@
#######################################################
lib.compiled : ./lib/*.c
	@make -C lib
	@${RM} $@
	@touch $@


.PHONY:clean all test
clean:
	@echo "正在删除所有编译时生成的文件"
	@${RM} ${output_dir}*.o arm_ucos.bin ${elf_output_dir}arm_ucos.elf \
	@${RM} *.compiled
	@make -C ${src_dir} clean
	@make -C start_code clean
	@make -C task clean
	@make -C dev clean
	@make -C s3c2440 clean
	@make -C lib clean
		
	