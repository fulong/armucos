include ../var.mk
source_src := $(wildcard *.c)
source_obj := $(patsubst %.c,%.o,$(source_src))
all: ${source_obj}
#	${LD} -o task.o ${source_obj}
	@cp *.o ../${output_dir} -rf
	

.PHONY:clean all
clean:
	@echo 正在删除task文件夹.0文件
	@${RM} *.o