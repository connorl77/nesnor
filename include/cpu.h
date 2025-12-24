#ifndef CPU_H
#define CPU_H

#define STACK_OFFSET 0x0100

#include <stdint.h>
#include <stdbool.h>
#include "bus.h"
#include "status_flag.h"

typedef struct {
	/* registers: accumulator, x, y, stack pointer, status register, program counter
	status register: bit 5 can not be changed and is always set to 1.
	   | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
	   | N | V | - | B | D | I | Z | C | */
	uint8_t acc, x, y, sp, sr;
	uint16_t pc;

	uint16_t addr_abs;
    uint16_t addr_rel;
    uint8_t fetched;

	uint8_t opcode;

    uint8_t cycles;

	Bus *bus;
} CPU;

typedef uint8_t (*op_fn)(CPU *cpu);
typedef uint8_t (*addr_fn)(CPU *cpu);

typedef struct {
    const char *name;
    op_fn operate;
    addr_fn addrmode;
    uint8_t cycles;
} Opcode;

void cpu_init(CPU *cpu);
void cpu_step(CPU *cpu);
void cpu_push(CPU *cpu, uint8_t val);

uint8_t cpu_read_byte(CPU *cpu, uint16_t address);
uint16_t cpu_read_word(CPU *cpu, uint16_t address);

void cpu_write_byte(CPU *cpu, uint16_t address, uint8_t data);
void cpu_write_word(CPU *cpu, uint16_t address, uint16_t data);

void set_flag(CPU *cpu, StatusFlag bit, bool val);
void set_zero_negative_flag(CPU *cpu, uint8_t val);

uint8_t ADC(CPU *cpu);
uint8_t AND(CPU *cpu);
uint8_t ASL(CPU *cpu);
uint8_t BCC(CPU *cpu);
uint8_t BCS(CPU *cpu);
uint8_t BEQ(CPU *cpu);
uint8_t BIT(CPU *cpu);
uint8_t BMI(CPU *cpu);
uint8_t BNE(CPU *cpu);
uint8_t BPL(CPU *cpu);
uint8_t BRK(CPU *cpu);
uint8_t BVC(CPU *cpu);
uint8_t BVS(CPU *cpu);
uint8_t CLC(CPU *cpu);
uint8_t CLD(CPU *cpu);
uint8_t CLI(CPU *cpu);
uint8_t CLV(CPU *cpu);
uint8_t CMP(CPU *cpu);
uint8_t CPX(CPU *cpu);
uint8_t CPY(CPU *cpu);
uint8_t DEC(CPU *cpu);
uint8_t DEX(CPU *cpu);
uint8_t DEY(CPU *cpu);
uint8_t EOR(CPU *cpu);
uint8_t INC(CPU *cpu);
uint8_t INX(CPU *cpu);
uint8_t INY(CPU *cpu);
uint8_t JMP(CPU *cpu);
uint8_t JSR(CPU *cpu);
uint8_t LDA(CPU *cpu);
uint8_t LDX(CPU *cpu);
uint8_t LDY(CPU *cpu);
uint8_t LSR(CPU *cpu);
uint8_t NOP(CPU *cpu);
uint8_t ORA(CPU *cpu);
uint8_t PHA(CPU *cpu);
uint8_t PHP(CPU *cpu);
uint8_t PLA(CPU *cpu);
uint8_t PLP(CPU *cpu);
uint8_t ROL(CPU *cpu);
uint8_t ROR(CPU *cpu);
uint8_t RTI(CPU *cpu);
uint8_t RTS(CPU *cpu);
uint8_t SBC(CPU *cpu);
uint8_t SEC(CPU *cpu);
uint8_t SED(CPU *cpu);
uint8_t SEI(CPU *cpu);
uint8_t STA(CPU *cpu);
uint8_t STX(CPU *cpu);
uint8_t STY(CPU *cpu);
uint8_t TAX(CPU *cpu);
uint8_t TAY(CPU *cpu);
uint8_t TSX(CPU *cpu);
uint8_t TXA(CPU *cpu);
uint8_t TXS(CPU *cpu);
uint8_t TYA(CPU *cpu);

uint8_t ILL(CPU *cpu); // illegal instruction

// other operations
uint8_t IRQ(CPU *cpu);
uint8_t NMI(CPU *cpu);

// Adressing modes
uint8_t ACC(CPU *cpu);
uint8_t IMP(CPU *cpu);
uint8_t IND(CPU *cpu); 
uint8_t IDX(CPU *cpu); 
uint8_t IDY(CPU *cpu); 
uint8_t IMM(CPU *cpu);
uint8_t IMP(CPU *cpu);
uint8_t ZP0(CPU *cpu);
uint8_t ZPX(CPU *cpu);
uint8_t ZPY(CPU *cpu);
uint8_t ABS(CPU *cpu);  
uint8_t ABX(CPU *cpu);
uint8_t ABY(CPU *cpu);
uint8_t REL(CPU *cpu); 

#endif
