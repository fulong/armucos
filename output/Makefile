include ../var.mk
source_src := $(wildcard *.o)
#source_src := 		start.o\
		clock.o	\
		string.o\
		_*.o\
		div0.o\
		nand.o\
		uart.o\
		debug.o\
		interrupt.o\
		led.o\
		app.o

all: ${source_obj}
	${LD} ${LD_FLAGS} -o ../${elf_output_dir}arm_ucos.elf ${source_src}	

.PHONY: all
