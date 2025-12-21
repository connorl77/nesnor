#include "cpu_ops.h"

uint8_t ADC(struct CPU *cpu){ return 0x00; }
uint8_t AND(struct CPU *cpu){ return 0x00; }
uint8_t ASL(struct CPU *cpu){ return 0x00; }
uint8_t BCC(struct CPU *cpu){ return 0x00; }
uint8_t BCS(struct CPU *cpu){ return 0x00; }
uint8_t BEQ(struct CPU *cpu){ return 0x00; }
uint8_t BIT(struct CPU *cpu){ return 0x00; }
uint8_t BMI(struct CPU *cpu){ return 0x00; }
uint8_t BNE(struct CPU *cpu){ return 0x00; }
uint8_t BPL(struct CPU *cpu){ return 0x00; }
uint8_t BRK(struct CPU *cpu){ return 0x00; }
uint8_t BVC(struct CPU *cpu){ return 0x00; }
uint8_t BVS(struct CPU *cpu){ return 0x00; }

uint8_t CLC(struct CPU *cpu)
{ 
	cpu->sr &= 0b11111110;

	return 0x00; 
}

uint8_t CLD(struct CPU *cpu)
{
	cpu->sr &= 0b11111110;

	return 0x00; 
}

uint8_t CLI(struct CPU *cpu){ 
	cpu->sr &= 0b11111011;

	return 0x00; 
}

uint8_t CLV(struct CPU *cpu){ 
	cpu->sr &= 0b10111111;

	return 0x00; 
}

uint8_t CMP(struct CPU *cpu){ return 0x00; }
uint8_t CPX(struct CPU *cpu){ return 0x00; }
uint8_t CPY(struct CPU *cpu){ return 0x00; }
uint8_t DEC(struct CPU *cpu){ return 0x00; }
uint8_t DEX(struct CPU *cpu)
{
	--cpu->x;

	return 0x00; 
}
uint8_t DEY(struct CPU *cpu){ return 0x00; }
uint8_t EOR(struct CPU *cpu){ return 0x00; }
uint8_t INC(struct CPU *cpu){ return 0x00; }
uint8_t INX(struct CPU *cpu){ return 0x00; }
uint8_t INY(struct CPU *cpu){ return 0x00; }
uint8_t JMP(struct CPU *cpu){ return 0x00; }
uint8_t JSR(struct CPU *cpu){ return 0x00; }
uint8_t LDA(struct CPU *cpu){ return 0x00; }
uint8_t LDX(struct CPU *cpu){ return 0x00; }
uint8_t LDY(struct CPU *cpu){ return 0x00; }
uint8_t LSR(struct CPU *cpu){ return 0x00; }
uint8_t NOP(struct CPU *cpu){ return 0x00; }
uint8_t ORA(struct CPU *cpu){ return 0x00; }
uint8_t PHA(struct CPU *cpu){ return 0x00; }
uint8_t PHP(struct CPU *cpu){ return 0x00; }
uint8_t PLA(struct CPU *cpu){ return 0x00; }
uint8_t PLP(struct CPU *cpu){ return 0x00; }
uint8_t ROL(struct CPU *cpu){ return 0x00; }
uint8_t ROR(struct CPU *cpu){ return 0x00; }
uint8_t RTI(struct CPU *cpu){ return 0x00; }
uint8_t RTS(struct CPU *cpu){ return 0x00; }
uint8_t SBC(struct CPU *cpu){ return 0x00; }
uint8_t SEC(struct CPU *cpu){ return 0x00; }
uint8_t SED(struct CPU *cpu){ return 0x00; }
uint8_t SEI(struct CPU *cpu){ return 0x00; }
uint8_t STA(struct CPU *cpu){ return 0x00; }
uint8_t STX(struct CPU *cpu){ return 0x00; }
uint8_t STY(struct CPU *cpu){ return 0x00; }
uint8_t TAX(struct CPU *cpu){ return 0x00; }
uint8_t TAY(struct CPU *cpu){ return 0x00; }
uint8_t TSX(struct CPU *cpu){ return 0x00; }
uint8_t TXA(struct CPU *cpu){ return 0x00; }
uint8_t TXS(struct CPU *cpu){ return 0x00; }
uint8_t TYA(struct CPU *cpu){ return 0x00; }

uint8_t ILL(struct CPU *cpu){ return 0x00; } // illegal instruction

// other operations
void IRQ(struct CPU *cpu)
{ 
}

void NMI(struct CPU *cpu)
{
}

void IMP(struct CPU *cpu) 
{
}

void IMM(struct CPU *cpu)
{
	cpu->addr_abs = cpu->pc++;
}

void ZP0(struct CPU *cpu)
{
}

void ABS(struct CPU *cpu)
{
	cpu->addr_abs = cpu->fetched;
	pc++;
}

void REL(struct CPU *cpu)
{
}
