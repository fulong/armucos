#目录变量
elf_output_dir := elf_output/
output_dir := output/
cpu_dir := s3c2440/
src_dir := ucos_src/
tsk_cfg_dir := task_configure/

#命令变量
CC := arm-uclinuxeabi-gcc
CFLAGS := -c -Wall -march=armv4t -O2
LD := arm-uclinuxeabi-ld
LD_FLAGS := -Tarm_ucos.lds 
OBJCOPY_FLAGS := -O binary -S
OBJCOPY := arm-uclinuxeabi-objcopy
OBJDUMP := arm-uclinuxeabi-objdump
OBJDUMP_FLAGS := -D -m arm