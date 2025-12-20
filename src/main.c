#include "cpu.h"
#include "mem.h"

#include <stdint.h>
#include <stdio.h>

int main(void)
{
	struct CPU cpu;
	cpu_init(&cpu);

	memory_init();	

	write_byte(0xF0CD, 0x21);
	printf("MEM:%i\n",  read_byte(0xF0CD));
	printf("MEM:%i\n",  read_byte(0xFFFF));
	printf("CPU:%i\n", cpu.sp); 
}
