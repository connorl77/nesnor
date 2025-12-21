#ifndef CPU_H
#define CPU_H

#include <stdint.h>

struct CPU {
	/* registers: accumulator, x, y, stack pointer, status register, program counter
	status register: bit 5 can not be changed and is always set to 1.
	   | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
	   | N | V | - | B | D | I | Z | C | */
	uint8_t acc, x, y, sp, sr;
	uint16_t pc;

	uint16_t addr_abs;
    uint16_t addr_rel;
    uint8_t fetched;

    uint8_t cycles;
};

typedef uint8_t (*op_fn)(struct CPU *cpu);
typedef void (*addr_fn)(struct CPU *cpu);

typedef struct {
    const char *name;
    op_fn operate;
    addr_fn addrmode;
    uint8_t cycles;
} Opcode;


void cpu_init(struct CPU *cpu);

#endif
