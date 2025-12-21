#include "mem.h"
#include "cpu.h"

#include <stdint.h>

int main(void)
{
	CPU cpu;
	cpu_init(&cpu);

	memory_init();	

	return 0;
}
