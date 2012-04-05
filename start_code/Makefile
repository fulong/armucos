include ../var.mk
source_src := $(wildcard *.S)
source_obj := $(patsubst %.S,%.o,$(source_src))
source_h := $(wildcard *.h)

all:${source_obj} ${source_h}
	@make -C lib
	@cp *.o ../${output_dir} -rf
	

.PHONY:clean all
clean:
	@echo 正在删除start_code文件夹.0文件
	@make -C lib clean
	@${RM} *.o