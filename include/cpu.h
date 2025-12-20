#ifndef CPU_H
#define CPU_H

#include <stdint.h>

struct CPU {
	uint8_t acc;
	uint8_t x;
	uint8_t y;
	uint8_t sp;
	uint8_t sr;
	uint16_t pc;
};

void cpu_init(struct CPU *cpu);

#endif
