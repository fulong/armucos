include ../../var.mk
source_src := $(wildcard *.S)
source_obj := $(patsubst %.S,%.o,$(source_src))
source_h := $(wildcard *.h)
source_obj += div0.o

all:${source_obj} ${source_h}
	@cp *.o ../../${output_dir} -rf
	

.PHONY:clean all
clean:
	@echo 正在删除start_code/lib/文件夹.0文件
	@${RM} *.o