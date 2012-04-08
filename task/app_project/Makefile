include ../../var.mk
source_src := $(wildcard *.c)
source_obj := $(patsubst %.c,%.o,$(source_src))
source_h := $(wildcard *.h)
all: ${source_obj} ${source_h}
#	${LD} -o task.o ${source_obj}
	@mv *.o ../ 
	

.PHONY:all
