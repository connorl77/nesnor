#ifndef CPU_OPS_H
#define CPU_OPS_H

#include "cpu.h"
#include <stdint.h>

uint8_t ADC(struct CPU *cpu);
uint8_t AND(struct CPU *cpu);
uint8_t ASL(struct CPU *cpu);
uint8_t BCC(struct CPU *cpu);
uint8_t BCS(struct CPU *cpu);
uint8_t BEQ(struct CPU *cpu);
uint8_t BIT(struct CPU *cpu);
uint8_t BMI(struct CPU *cpu);
uint8_t BNE(struct CPU *cpu);
uint8_t BPL(struct CPU *cpu);
uint8_t BRK(struct CPU *cpu);
uint8_t BVC(struct CPU *cpu);
uint8_t BVS(struct CPU *cpu);
uint8_t CLC(struct CPU *cpu);
uint8_t CLD(struct CPU *cpu);
uint8_t CLI(struct CPU *cpu);
uint8_t CLV(struct CPU *cpu);
uint8_t CMP(struct CPU *cpu);
uint8_t CPX(struct CPU *cpu);
uint8_t CPY(struct CPU *cpu);
uint8_t DEC(struct CPU *cpu);
uint8_t DEX(struct CPU *cpu);
uint8_t DEY(struct CPU *cpu);
uint8_t EOR(struct CPU *cpu);
uint8_t INC(struct CPU *cpu);
uint8_t INX(struct CPU *cpu);
uint8_t INY(struct CPU *cpu);
uint8_t JMP(struct CPU *cpu);
uint8_t JSR(struct CPU *cpu);
uint8_t LDA(struct CPU *cpu);
uint8_t LDX(struct CPU *cpu);
uint8_t LDY(struct CPU *cpu);
uint8_t LSR(struct CPU *cpu);
uint8_t NOP(struct CPU *cpu);
uint8_t ORA(struct CPU *cpu);
uint8_t PHA(struct CPU *cpu);
uint8_t PHP(struct CPU *cpu);
uint8_t PLA(struct CPU *cpu);
uint8_t PLP(struct CPU *cpu);
uint8_t ROL(struct CPU *cpu);
uint8_t ROR(struct CPU *cpu);
uint8_t RTI(struct CPU *cpu);
uint8_t RTS(struct CPU *cpu);
uint8_t SBC(struct CPU *cpu);
uint8_t SEC(struct CPU *cpu);
uint8_t SED(struct CPU *cpu);
uint8_t SEI(struct CPU *cpu);
uint8_t STA(struct CPU *cpu);
uint8_t STX(struct CPU *cpu);
uint8_t STY(struct CPU *cpu);
uint8_t TAX(struct CPU *cpu);
uint8_t TAY(struct CPU *cpu);
uint8_t TSX(struct CPU *cpu);
uint8_t TXA(struct CPU *cpu);
uint8_t TXS(struct CPU *cpu);
uint8_t TYA(struct CPU *cpu);

uint8_t ILL(struct CPU *cpu); // illegal instruction

// other operations
void IRQ(struct CPU *cpu);
void NMI(struct CPU *cpu);

void IMP(struct CPU *cpu);
void IMM(struct CPU *cpu);
void ZP0(struct CPU *cpu);
void ABS(struct CPU *cpu);  
void REL(struct CPU *cpu); 

#endif
