include ../var.mk
source_src := $(wildcard *.c)
source_obj := $(patsubst %.c,%.o,$(source_src))
source_h := $(wildcard *.h)
all:${source_obj} ${source_h}

	@cp *.o ../${output_dir} -rf
	

.PHONY:clean all
clean:
	@echo 正在删除dev文件夹.0文件
	@${RM} *.o