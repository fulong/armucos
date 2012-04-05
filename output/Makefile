include ../var.mk
source_src := $(wildcard *.o)
all: ${source_obj}
	${LD} ${LD_FLAGS} -o ../${elf_output_dir}arm_ucos.elf ${source_src}	

.PHONY: all
