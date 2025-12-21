#include "cpu.h"
#include "mem.h"

Opcode opcode_table[256] = {
    { "BRK", BRK, IMM, 7 },
};

void cpu_init(CPU *cpu)
{
	cpu->acc = 0x00;
	cpu->x = 0x00;
	cpu->y = 0x00;
	cpu->sp = 0xFF;
	cpu->sr = 0b00100000;
	cpu->pc = 0x0000;
}

uint8_t cpu_fetch(CPU *cpu)
{
    if (opcode_table[cpu->opcode].addrmode != IMP)
	{
        cpu->fetched = read_byte(cpu->addr_abs);
	}

    return cpu->fetched;
}

uint8_t ADC(CPU *cpu){ return 0x00; }
uint8_t AND(CPU *cpu){ return 0x00; }
uint8_t ASL(CPU *cpu){ return 0x00; }
uint8_t BCC(CPU *cpu){ return 0x00; }
uint8_t BCS(CPU *cpu){ return 0x00; }
uint8_t BEQ(CPU *cpu){ return 0x00; }
uint8_t BIT(CPU *cpu){ return 0x00; }
uint8_t BMI(CPU *cpu){ return 0x00; }
uint8_t BNE(CPU *cpu){ return 0x00; }
uint8_t BPL(CPU *cpu){ return 0x00; }
uint8_t BRK(CPU *cpu){ return 0x00; }
uint8_t BVC(CPU *cpu){ return 0x00; }
uint8_t BVS(CPU *cpu){ return 0x00; }

uint8_t CLC(CPU *cpu)
{ 
	cpu->sr &= 0b11111110;

	return 0x00; 
}

uint8_t CLD(CPU *cpu)
{
	cpu->sr &= 0b11111110;

	return 0x00; 
}

uint8_t CLI(CPU *cpu){ 
	cpu->sr &= 0b11111011;

	return 0x00; 
}

uint8_t CLV(CPU *cpu){ 
	cpu->sr &= 0b10111111;

	return 0x00; 
}

uint8_t CMP(CPU *cpu){ return 0x00; }
uint8_t CPX(CPU *cpu){ return 0x00; }
uint8_t CPY(CPU *cpu){ return 0x00; }
uint8_t DEC(CPU *cpu){ return 0x00; }
uint8_t DEX(CPU *cpu)
{
	--cpu->x;

	return 0x00; 
}
uint8_t DEY(CPU *cpu){ return 0x00; }
uint8_t EOR(CPU *cpu){ return 0x00; }
uint8_t INC(CPU *cpu){ return 0x00; }
uint8_t INX(CPU *cpu){ return 0x00; }
uint8_t INY(CPU *cpu){ return 0x00; }
uint8_t JMP(CPU *cpu){ return 0x00; }
uint8_t JSR(CPU *cpu){ return 0x00; }
uint8_t LDA(CPU *cpu){ return 0x00; }
uint8_t LDX(CPU *cpu){ return 0x00; }
uint8_t LDY(CPU *cpu){ return 0x00; }
uint8_t LSR(CPU *cpu){ return 0x00; }
uint8_t NOP(CPU *cpu){ return 0x00; }
uint8_t ORA(CPU *cpu){ return 0x00; }
uint8_t PHA(CPU *cpu){ return 0x00; }
uint8_t PHP(CPU *cpu){ return 0x00; }
uint8_t PLA(CPU *cpu){ return 0x00; }
uint8_t PLP(CPU *cpu){ return 0x00; }
uint8_t ROL(CPU *cpu){ return 0x00; }
uint8_t ROR(CPU *cpu){ return 0x00; }
uint8_t RTI(CPU *cpu){ return 0x00; }
uint8_t RTS(CPU *cpu){ return 0x00; }
uint8_t SBC(CPU *cpu){ return 0x00; }
uint8_t SEC(CPU *cpu){ return 0x00; }
uint8_t SED(CPU *cpu){ return 0x00; }
uint8_t SEI(CPU *cpu){ return 0x00; }
uint8_t STA(CPU *cpu){ return 0x00; }
uint8_t STX(CPU *cpu){ return 0x00; }
uint8_t STY(CPU *cpu){ return 0x00; }
uint8_t TAX(CPU *cpu){ return 0x00; }
uint8_t TAY(CPU *cpu){ return 0x00; }
uint8_t TSX(CPU *cpu){ return 0x00; }
uint8_t TXA(CPU *cpu){ return 0x00; }
uint8_t TXS(CPU *cpu){ return 0x00; }
uint8_t TYA(CPU *cpu){ return 0x00; }

uint8_t ILL(CPU *cpu){ return 0x00; } // illegal instruction

// other operations
void IRQ(CPU *cpu)
{ 
}

void NMI(CPU *cpu)
{
}

void IMP(CPU *cpu) 
{
}

void IMM(CPU *cpu)
{
	cpu->addr_abs = cpu->pc++;
}

void ZP0(CPU *cpu)
{
}

void ABS(CPU *cpu)
{
	cpu->addr_abs = cpu->fetched;
	cpu->pc++;
}

void REL(CPU *cpu)
{
}
