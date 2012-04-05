SECTIONS
{
	. = 0x30000000;
	.text : {*(.text)}
	.data : {*(.data)}
	.bss : {*(.bss)}
	
}