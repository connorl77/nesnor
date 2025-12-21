#include "cpu.h"
#include "mem.h"

#include <stdint.h>
#include <stdio.h>

int main(void)
{
	struct CPU cpu;
	cpu_init(&cpu);

	memory_init();	

	return 0;
}
