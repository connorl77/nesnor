#include "cpu.h"

void cpu_init(struct CPU *cpu)
{
	cpu->acc = 0x00;
	cpu->x = 0x00;
	cpu->y = 0x00;
	cpu->sp = 0xFF;
	cpu->sr = 0b00100000;
	cpu->pc = 0x0000;
}
