ENTRY(_start)
SECTIONS
{
	. = 0x30000000;
	.text : {
		start.o	(.text)
		clock.o	(.text)
		string.o	(.text)
		_*.o	(.text)
		div0.o	(.text)
		nand.o	(.text)
		uart.o	(.text)
		debug.o	(.text)
		interrupt.o	(.text)
		led.o	(.text)
		*(.text)
		}
	.data : {*(.data)}
	.bss : {*(.bss)}
	
}