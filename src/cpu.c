#include "cpu.h"

Opcode opcode_table[256] = 
{
	/* 0x00 */
	{ "BRK", BRK, IMP, 7 }, { "ORA", ORA, IDX, 6 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZP0, 3 }, { "ORA", ORA, ZP0, 3 }, { "ASL", ASL, ZP0, 5 }, { "???", ILL, IMP, 2 },
	{ "PHP", PHP, IMP, 3 }, { "ORA", ORA, IMM, 2 }, { "ASL", ASL, ACC, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABS, 4 }, { "ORA", ORA, ABS, 4 }, { "ASL", ASL, ABS, 6 }, { "???", ILL, IMP, 2 },

	/* 0x10 */
	{ "BPL", BPL, REL, 2 }, { "ORA", ORA, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZPX, 4 }, { "ORA", ORA, ZPX, 4 }, { "ASL", ASL, ZPX, 6 }, { "???", ILL, IMP, 2 },
	{ "CLC", CLC, IMP, 2 }, { "ORA", ORA, ABY, 4 }, { "NOP", NOP, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 4 }, { "ORA", ORA, ABX, 4 }, { "ASL", ASL, ABX, 7 }, { "???", ILL, IMP, 2 },

	/* 0x20 */
	{ "JSR", JSR, ABS, 6 }, { "AND", AND, IDX, 6 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "BIT", BIT, ZP0, 3 }, { "AND", AND, ZP0, 3 }, { "ROL", ROL, ZP0, 5 }, { "???", ILL, IMP, 2 },
	{ "PLP", PLP, IMP, 4 }, { "AND", AND, IMM, 2 }, { "ROL", ROL, ACC, 2 }, { "???", ILL, IMP, 2 },
	{ "BIT", BIT, ABS, 4 }, { "AND", AND, ABS, 4 }, { "ROL", ROL, ABS, 6 }, { "???", ILL, IMP, 2 },

	/* 0x30 */
	{ "BMI", BMI, REL, 2 }, { "AND", AND, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZPX, 4 }, { "AND", AND, ZPX, 4 }, { "ROL", ROL, ZPX, 6 }, { "???", ILL, IMP, 2 },
	{ "SEC", SEC, IMP, 2 }, { "AND", AND, ABY, 4 }, { "NOP", NOP, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 4 }, { "AND", AND, ABX, 4 }, { "ROL", ROL, ABX, 7 }, { "???", ILL, IMP, 2 },

	/* 0x40 */
	{ "RTI", RTI, IMP, 6 }, { "EOR", EOR, IDX, 6 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZP0, 3 }, { "EOR", EOR, ZP0, 3 }, { "LSR", LSR, ZP0, 5 }, { "???", ILL, IMP, 2 },
	{ "PHA", PHA, IMP, 3 }, { "EOR", EOR, IMM, 2 }, { "LSR", LSR, ACC, 2 }, { "???", ILL, IMP, 2 },
	{ "JMP", JMP, ABS, 3 }, { "EOR", EOR, ABS, 4 }, { "LSR", LSR, ABS, 6 }, { "???", ILL, IMP, 2 },

	/* 0x50 */
	{ "BVC", BVC, REL, 2 }, { "EOR", EOR, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZPX, 4 }, { "EOR", EOR, ZPX, 4 }, { "LSR", LSR, ZPX, 6 }, { "???", ILL, IMP, 2 },
	{ "CLI", CLI, IMP, 2 }, { "EOR", EOR, ABY, 4 }, { "NOP", NOP, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 4 }, { "EOR", EOR, ABX, 4 }, { "LSR", LSR, ABX, 7 }, { "???", ILL, IMP, 2 },

	/* 0x60 */
	{ "RTS", RTS, IMP, 6 }, { "ADC", ADC, IDX, 6 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZP0, 3 }, { "ADC", ADC, ZP0, 3 }, { "ROR", ROR, ZP0, 5 }, { "???", ILL, IMP, 2 },
	{ "PLA", PLA, IMP, 4 }, { "ADC", ADC, IMM, 2 }, { "ROR", ROR, ACC, 2 }, { "???", ILL, IMP, 2 },
	{ "JMP", JMP, IND, 5 }, { "ADC", ADC, ABS, 4 }, { "ROR", ROR, ABS, 6 }, { "???", ILL, IMP, 2 },

	/* 0x70 */
	{ "BVS", BVS, REL, 2 }, { "ADC", ADC, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZPX, 4 }, { "ADC", ADC, ZPX, 4 }, { "ROR", ROR, ZPX, 6 }, { "???", ILL, IMP, 2 },
	{ "SEI", SEI, IMP, 2 }, { "ADC", ADC, ABY, 4 }, { "NOP", NOP, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 4 }, { "ADC", ADC, ABX, 4 }, { "ROR", ROR, ABX, 7 }, { "???", ILL, IMP, 2 },

	/* 0x80 */
	{ "NOP", NOP, IMM, 2 }, { "STA", STA, IDX, 6 }, { "NOP", NOP, IMM, 2 }, { "???", ILL, IMP, 2 },
	{ "STY", STY, ZP0, 3 }, { "STA", STA, ZP0, 3 }, { "STX", STX, ZP0, 3 }, { "???", ILL, IMP, 2 },
	{ "DEY", DEY, IMP, 2 }, { "NOP", NOP, IMM, 2 }, { "TXA", TXA, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "STY", STY, ABS, 4 }, { "STA", STA, ABS, 4 }, { "STX", STX, ABS, 4 }, { "???", ILL, IMP, 2 },

	/* 0x90 */
	{ "BCC", BCC, REL, 2 }, { "STA", STA, IDY, 6 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "STY", STY, ZPX, 4 }, { "STA", STA, ZPX, 4 }, { "STX", STX, ZPY, 4 }, { "???", ILL, IMP, 2 },
	{ "TYA", TYA, IMP, 2 }, { "STA", STA, ABY, 5 }, { "TXS", TXS, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 5 }, { "STA", STA, ABX, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },

	/* 0xA0 */
	{ "LDY", LDY, IMM, 2 }, { "LDA", LDA, IDX, 6 }, { "LDX", LDX, IMM, 2 }, { "???", ILL, IMP, 2 },
	{ "LDY", LDY, ZP0, 3 }, { "LDA", LDA, ZP0, 3 }, { "LDX", LDX, ZP0, 3 }, { "???", ILL, IMP, 2 },
	{ "TAY", TAY, IMP, 2 }, { "LDA", LDA, IMM, 2 }, { "TAX", TAX, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "LDY", LDY, ABS, 4 }, { "LDA", LDA, ABS, 4 }, { "LDX", LDX, ABS, 4 }, { "???", ILL, IMP, 2 },

	/* 0xB0 */
	{ "BCS", BCS, REL, 2 }, { "LDA", LDA, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "LDY", LDY, ZPX, 4 }, { "LDA", LDA, ZPX, 4 }, { "LDX", LDX, ZPY, 4 }, { "???", ILL, IMP, 2 },
	{ "CLV", CLV, IMP, 2 }, { "LDA", LDA, ABY, 4 }, { "TSX", TSX, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "LDY", LDY, ABX, 4 }, { "LDA", LDA, ABX, 4 }, { "LDX", LDX, ABY, 4 }, { "???", ILL, IMP, 2 },

	/* 0xC0 */
	{ "CPY", CPY, IMM, 2 }, { "CMP", CMP, IDX, 6 }, { "NOP", NOP, IMM, 2 }, { "???", ILL, IMP, 2 },
	{ "CPY", CPY, ZP0, 3 }, { "CMP", CMP, ZP0, 3 }, { "DEC", DEC, ZP0, 5 }, { "???", ILL, IMP, 2 },
	{ "INY", INY, IMP, 2 }, { "CMP", CMP, IMM, 2 }, { "DEX", DEX, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "CPY", CPY, ABS, 4 }, { "CMP", CMP, ABS, 4 }, { "DEC", DEC, ABS, 6 }, { "???", ILL, IMP, 2 },

	/* 0xD0 */
	{ "BNE", BNE, REL, 2 }, { "CMP", CMP, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZPX, 4 }, { "CMP", CMP, ZPX, 4 }, { "DEC", DEC, ZPX, 6 }, { "???", ILL, IMP, 2 },
	{ "CLD", CLD, IMP, 2 }, { "CMP", CMP, ABY, 4 }, { "NOP", NOP, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 4 }, { "CMP", CMP, ABX, 4 }, { "DEC", DEC, ABX, 7 }, { "???", ILL, IMP, 2 },

	/* 0xE0 */
	{ "CPX", CPX, IMM, 2 }, { "SBC", SBC, IDX, 6 }, { "NOP", NOP, IMM, 2 }, { "???", ILL, IMP, 2 },
	{ "CPX", CPX, ZP0, 3 }, { "SBC", SBC, ZP0, 3 }, { "INC", INC, ZP0, 5 }, { "???", ILL, IMP, 2 },
	{ "INX", INX, IMP, 2 }, { "SBC", SBC, IMM, 2 }, { "NOP", NOP, IMP, 2 }, { "SBC", SBC, IMP, 2 },
	{ "CPX", CPX, ABS, 4 }, { "SBC", SBC, ABS, 4 }, { "INC", INC, ABS, 6 }, { "???", ILL, IMP, 2 },

	/* 0xF0 */
	{ "BEQ", BEQ, REL, 2 }, { "SBC", SBC, IDY, 5 }, { "???", ILL, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ZPX, 4 }, { "SBC", SBC, ZPX, 4 }, { "INC", INC, ZPX, 6 }, { "???", ILL, IMP, 2 },
	{ "SED", SED, IMP, 2 }, { "SBC", SBC, ABY, 4 }, { "NOP", NOP, IMP, 2 }, { "???", ILL, IMP, 2 },
	{ "NOP", NOP, ABX, 4 }, { "SBC", SBC, ABX, 4 }, { "INC", INC, ABX, 7 }, { "???", ILL, IMP, 2 }
};

void cpu_init(CPU *cpu)
{
	cpu->acc = 0x00;
	cpu->x = 0x00;
	cpu->y = 0x00;
	cpu->sp = 0xFF;
	cpu->sr = 0b00100000;

	uint8_t lo = cpu_read_byte(cpu, 0xFFFC);
	uint8_t hi = cpu_read_byte(cpu, 0xFFFD);

	cpu->pc = (hi << 8) | lo;
}

void stack_push(CPU *cpu, uint8_t value) {
    cpu_write_byte(cpu, STACK_OFFSET + cpu->sp, value);
    cpu->sp--;
}

uint8_t stack_pop(CPU *cpu) {
    cpu->sp++;
    return cpu_read_byte(cpu, STACK_OFFSET + cpu->sp);
}

uint8_t cpu_read_byte(CPU *cpu, uint16_t address)
{
	return bus_read_byte(cpu->bus, address);
}

uint16_t cpu_read_word(CPU *cpu, uint16_t address)
{
	return bus_read_word(cpu->bus, address);
}

void cpu_write_byte(CPU *cpu, uint16_t address, uint8_t data)
{
	bus_write_byte(cpu->bus, address, data);
}

void cpu_write_word(CPU *cpu, uint16_t address, uint16_t data)
{
	bus_write_word(cpu->bus, address, data);
}

bool get_flag(CPU *cpu, StatusFlag flag)
{
	switch (flag)
	{
		case CARRY:
			return (cpu->sr & 0b00000001) > 0;
		case ZERO:
			return (cpu->sr & 0b00000010) > 0;
		case INTERRUPT_DISABLE:
			return (cpu->sr & 0b00000100) > 0;
		case DECIMAL:
			return (cpu->sr & 0b00001000) > 0;
		case BREAK:
			return (cpu->sr & 0b00010000) > 0;
		case UNUSED:
			return true;
		case OVERFLOW:
			return (cpu->sr & 0b01000000) > 0;
		case NEGATIVE:
			return (cpu->sr & 0b10000000) > 0;
		};
}

void set_flag(CPU *cpu, StatusFlag flag, bool val)
{
	switch (flag)
	{
		case CARRY:
			cpu->sr = val ? cpu->sr | 0b00000001 : cpu->sr & 0b11111110;
			break;
		case ZERO:
			cpu->sr = val ? cpu->sr | 0b00000010 : cpu->sr & 0b11111101;
			break;
		case INTERRUPT_DISABLE:
			cpu->sr = val ? cpu->sr | 0b00000100 : cpu->sr & 0b11111011;
			break;
		case DECIMAL:
			cpu->sr = val ? cpu->sr | 0b00001000 : cpu->sr & 0b11110111;
			break;
		case BREAK:
			cpu->sr = val ? cpu->sr | 0b00010000 : cpu->sr & 0b11101111;
			break;
		case UNUSED:
			break;
		case OVERFLOW:
			cpu->sr = val ? cpu->sr | 0b01000000 : cpu->sr & 0b10111111;
			break;
		case NEGATIVE:
			cpu->sr = val ? cpu->sr | 0b10000000 : cpu->sr & 0b01111111;
			break;
		};
}

void set_zero_negative_flag(CPU *cpu, uint8_t val)
{
	if (val == 0)
	{
		set_flag(cpu, ZERO, true);
	}

	set_flag(cpu, NEGATIVE, val & 0b10000000);
}

uint8_t cpu_fetch(CPU *cpu)
{
    if (opcode_table[cpu->opcode].addrmode != IMP)
	{
        cpu->fetched = cpu_read_byte(cpu, cpu->addr_abs);
	}

    return cpu->fetched;
}

void cpu_step(CPU *cpu)
{
    cpu->opcode = cpu_read_byte(cpu, cpu->pc++);
    Opcode *op = &opcode_table[cpu->opcode];

    cpu->cycles = op->cycles;

    uint8_t extra1 = op->addrmode(cpu);
    uint8_t extra2 = op->operate(cpu);

    cpu->cycles += (extra1 & extra2);
}

uint8_t ADC(CPU *cpu)
{ 
	uint8_t fetched_data = cpu_fetch(cpu);
	uint16_t temp_result = cpu->acc + fetched_data + get_flag(cpu, CARRY);

	if (temp_result > 0xFF)
	{
		set_flag(cpu, CARRY, true);
	}

	set_zero_negative_flag(cpu, temp_result); // likely wrong.
	~(cpu->acc ^ fetched_data) & (cpu->acc ^ temp_result) & 0b10000000 
		? (cpu->sr |= 0b01000000) 
		: (cpu->sr &= 0b10111111);

	cpu->acc = temp_result & 0xFF;

	return 0x00; 
}

uint8_t AND(CPU *cpu)
{ 
	cpu->acc &= cpu_fetch(cpu);
	cpu->pc++;

	set_zero_negative_flag(cpu, cpu->acc);

	return 0x00; 
}

uint8_t ASL(CPU *cpu)
{ 
	uint8_t new_data = (cpu_read_byte(cpu, cpu->pc)) << 1;
	cpu_write_byte(cpu, cpu->pc, new_data);

	set_flag(cpu, ZERO, new_data == 0);

	cpu->pc++;

	return 0x00; 
}

uint8_t BCC(CPU *cpu)
{ 
	if (!get_flag(cpu, CARRY))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BCS(CPU *cpu)
{ 
	if (get_flag(cpu, CARRY))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BEQ(CPU *cpu)
{ 
	if (get_flag(cpu, ZERO))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BIT(CPU *cpu)
{ 
	uint8_t data = cpu_fetch(cpu);

	set_flag(cpu, ZERO, (cpu->acc & data) == 0);

	(data & 0b10000000) > 0 
		? (cpu->sr |= 0b10000000) 
		: (cpu->sr &= 0b01111111);

	(data & 0b01000000) > 0 
		? (cpu->sr |= 0b01000000) 
		: (cpu->sr &= 0b10111111);

	return 0x00; 
}

uint8_t BMI(CPU *cpu)
{ 
	if (get_flag(cpu, NEGATIVE))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BNE(CPU *cpu)
{ 
	if (!get_flag(cpu, ZERO))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BPL(CPU *cpu)
{ 
	if (!get_flag(cpu, NEGATIVE))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BRK(CPU *cpu)
{ 
	uint8_t hi = cpu->pc >> 8;
	uint8_t lo = cpu->pc & 0xFF;

	stack_push(cpu, lo);
	stack_push(cpu, hi);
	stack_push(cpu, cpu->sr);

	cpu->pc = 0xFFFE;

	set_flag(cpu, BREAK, true);

	return 0x00; 
}

uint8_t BVC(CPU *cpu)
{ 
	if (!get_flag(cpu, OVERFLOW))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t BVS(CPU *cpu)
{ 
	if (get_flag(cpu, OVERFLOW))
	{
		cpu->addr_abs = cpu->addr_rel + cpu->pc;
		cpu->pc = cpu->addr_abs;
	}

	return 0x00; 
}

uint8_t CLC(CPU *cpu)
{ 
	set_flag(cpu, CARRY, false);

	return 0x00; 
}

uint8_t CLD(CPU *cpu)
{
	set_flag(cpu, DECIMAL, false);

	return 0x00; 
}

uint8_t CLI(CPU *cpu)
{ 
	set_flag(cpu, INTERRUPT_DISABLE, false);

	return 0x00; 
}

uint8_t CLV(CPU *cpu)
{ 
	set_flag(cpu, OVERFLOW, false);

	return 0x00; 
}

uint8_t CMP(CPU *cpu)
{ 
	uint8_t data = cpu_fetch(cpu);
	cpu->pc++;

	set_flag(cpu, CARRY, cpu->acc >= data);
	set_flag(cpu, ZERO, cpu->acc == data);
	set_flag(cpu, NEGATIVE, cpu->acc & 0b10000000);

	return 0x00; 
}

uint8_t CPX(CPU *cpu)
{ 
	uint8_t data = cpu_fetch(cpu);
	cpu->pc++;

	set_flag(cpu, CARRY, cpu->x >= data);
	set_flag(cpu, ZERO, cpu->x == data);
	set_flag(cpu, NEGATIVE, cpu->x & 0b10000000);

	return 0x00; 
}

uint8_t CPY(CPU *cpu)
{ 
	uint8_t data = cpu_fetch(cpu);
	cpu->pc++;

	set_flag(cpu, CARRY, cpu->y >= data);
	set_flag(cpu, ZERO, cpu->y == data);
	set_flag(cpu, NEGATIVE, cpu->y & 0b10000000);

	return 0x00; 
}

uint8_t DEC(CPU *cpu)
{ 
	uint8_t new_val = (cpu_fetch(cpu) - 1);
	cpu->pc++;

	cpu_write_byte(cpu, cpu->addr_abs, new_val);

	set_zero_negative_flag(cpu, new_val);

	return 0x00; 
}

uint8_t DEX(CPU *cpu)
{
	--cpu->x;

	set_zero_negative_flag(cpu, cpu->x);

	return 0x00; 
}

uint8_t DEY(CPU *cpu)
{ 
	--cpu->y;

	set_zero_negative_flag(cpu, cpu->y);

	return 0x00; 
}

uint8_t EOR(CPU *cpu){ 
	cpu->acc ^= cpu_fetch(cpu);
	cpu->pc++;

	set_zero_negative_flag(cpu, cpu->acc);

	return 0x00; 
}

uint8_t INC(CPU *cpu)
{ 
	uint8_t new_val = (cpu_fetch(cpu) + 1);
	cpu->pc++;

	cpu_write_byte(cpu, cpu->addr_abs, new_val);

	set_zero_negative_flag(cpu, new_val);

	return 0x00; 
}

uint8_t INX(CPU *cpu)
{ 
	++cpu->x;

	set_zero_negative_flag(cpu, cpu->x);

	return 0x00; 
}

uint8_t INY(CPU *cpu)
{ 
	++cpu->y;

	set_zero_negative_flag(cpu, cpu->y);

	return 0x00; 
}

uint8_t JMP(CPU *cpu)
{ 
	cpu->pc = cpu->addr_abs;

	return 0x00; 
}

uint8_t JSR(CPU *cpu)
{ 
	uint8_t hi = cpu->pc >> 8;
	uint8_t lo = cpu->pc & 0xFF;

	stack_push(cpu, hi);
	stack_push(cpu, lo);

	return 0x00; 
}

uint8_t LDA(CPU *cpu)
{ 
	cpu->acc = cpu_fetch(cpu);

	return 0x00; 
}

uint8_t LDX(CPU *cpu)
{ 
	cpu->x = cpu_fetch(cpu);

	return 0x00; 
}

uint8_t LDY(CPU *cpu)
{ 
	cpu->y = cpu_fetch(cpu);

	return 0x00; 
}

uint8_t LSR(CPU *cpu)
{ 
	uint8_t new_data = (cpu_read_byte(cpu, cpu->pc) >> 1);
	cpu_write_byte(cpu, cpu->pc, new_data);

	set_flag(cpu, ZERO, new_data == 0);

	cpu->pc++;

	return 0x00; 
}

uint8_t NOP(CPU *cpu)
{ 
	return 0x00; 
}

uint8_t ORA(CPU *cpu)
{ 
	cpu->acc |= cpu_fetch(cpu);

	return 0x00; 
}

uint8_t PHA(CPU *cpu)
{ 
	stack_push(cpu, cpu->acc);

	return 0x00; 
}

uint8_t PHP(CPU *cpu)
{ 
	stack_push(cpu, (cpu->sr & 0b11001111) | 0b00110000);

	return 0x00; 
}

uint8_t PLA(CPU *cpu)
{ 
	cpu->sp++;

	cpu->acc = stack_pop(cpu);

	return 0x00; 
}

uint8_t PLP(CPU *cpu)
{
	uint8_t pulled_sr = stack_pop(cpu);

    cpu->sr = (pulled_sr & 0x110011111) | 0b00100000;

	return 0x00; 
}

uint8_t ROL(CPU *cpu){ 
	uint8_t new_data = (cpu_read_byte(cpu, cpu->pc) << 1);
	cpu_write_byte(cpu, cpu->pc, new_data);

	set_flag(cpu, ZERO, new_data == 0);

	cpu->pc++;

	return 0x00; 
}

uint8_t ROR(CPU *cpu)
{
	uint8_t new_data = (cpu_read_byte(cpu, cpu->pc) >> 1);
	cpu_write_byte(cpu, cpu->pc, new_data);

	set_flag(cpu, ZERO, new_data == 0);

	cpu->pc++;

	return 0x00; 
}

uint8_t RTI(CPU *cpu) 
{
    uint8_t pulled_sr = stack_pop(cpu);
    
    cpu->sr = (pulled_sr & 0x110011111) | 0b00100000;

    uint8_t pc_lo = stack_pop(cpu);
    uint8_t pc_hi = stack_pop(cpu);

    cpu->pc = ((pc_hi << 8) | pc_lo);

    return 0x00; 
}

uint8_t RTS(CPU *cpu)
{ 
	cpu->pc = stack_pop(cpu);

	return 0x00; 
}

uint8_t SBC(CPU *cpu)
{
	cpu->fetched = ~(cpu_fetch(cpu));

	ADC(cpu);
	
	return 0x00; 
}

uint8_t SEC(CPU *cpu)
{ 
	set_flag(cpu, CARRY, true);

	return 0x00; 
}

uint8_t SED(CPU *cpu)
{ 
	set_flag(cpu, DECIMAL, true);

	return 0x00; 
}

uint8_t SEI(CPU *cpu)
{ 
	set_flag(cpu, INTERRUPT_DISABLE, true); // Delayed by one instruction?

	return 0x00; 
}

uint8_t STA(CPU *cpu)
{ 
	cpu_write_byte(cpu, cpu->pc, cpu->acc);

	return 0x00; 
}

uint8_t STX(CPU *cpu)
{ 
	cpu_write_byte(cpu, cpu->pc, cpu->x);

	return 0x00; 
}

uint8_t STY(CPU *cpu)
{ 
	cpu_write_byte(cpu, cpu->pc, cpu->y);

	return 0x00;
}

uint8_t TAX(CPU *cpu)
{ 
	cpu->x = cpu->acc;

	set_zero_negative_flag(cpu, cpu->x);

	return 0x00; 
}

uint8_t TAY(CPU *cpu)
{ 
	cpu->y = cpu->acc;

	set_zero_negative_flag(cpu, cpu->y);

	return 0x00; 
}

uint8_t TSX(CPU *cpu)
{ 
	cpu->x = cpu->sp;

	set_zero_negative_flag(cpu, cpu->x);

	return 0x00; 
}

uint8_t TXA(CPU *cpu)
{ 
	cpu->acc = cpu->x;

	set_zero_negative_flag(cpu, cpu->acc);

	return 0x00; 
}

uint8_t TXS(CPU *cpu)
{ 
	cpu->sp = cpu->x;

	set_zero_negative_flag(cpu, cpu->sp);

	return 0x00; 
}

uint8_t TYA(CPU *cpu)
{ 
	cpu->acc = cpu->y;

	set_zero_negative_flag(cpu, cpu->acc);

	return 0x00; 
}

uint8_t ILL(CPU *cpu)
{ 
	return 0x00; 
} 

uint8_t IRQ(CPU *cpu)
{ 
	return 0x00;
}

uint8_t NMI(CPU *cpu)
{
	return 0x00;
}

// Addressing modes
uint8_t ACC(CPU *cpu) 
{
	return 0x00;
}

uint8_t IND(CPU *cpu) 
{
	uint8_t lo_ptr = cpu_fetch(cpu);
	uint8_t hi_ptr = cpu_fetch(cpu);

	uint16_t ptr = (hi_ptr << 8) | lo_ptr;

	cpu->addr_abs = lo_ptr == 0xFF 
		? (cpu_read_byte(cpu, ptr & 0xFF00) << 8) | cpu_read_byte(cpu, ptr)
		: (cpu_read_byte(cpu, ptr + 1) << 8) | cpu_read_byte(cpu, ptr);

	return 0x00;
}

uint8_t IDY(CPU *cpu) 
{
	uint8_t tmp = cpu_fetch(cpu);

	uint8_t lo = cpu_read_byte(cpu, (tmp + cpu->y) & 0xFF);
	uint8_t hi = cpu_read_byte(cpu, (tmp + cpu->y + 1) & 0xFF);

	cpu->addr_abs = (hi << 8) | lo;

	return 0x00;
}

uint8_t IDX(CPU *cpu) 
{
	uint8_t tmp = cpu_fetch(cpu);

	uint8_t lo = cpu_read_byte(cpu, (tmp + cpu->x) & 0xFF);
	uint8_t hi = cpu_read_byte(cpu, (tmp + cpu->x + 1) & 0xFF);

	cpu->addr_abs = (hi << 8) | lo;

	return 0x00;
}

uint8_t IMM(CPU *cpu)
{
	cpu->addr_abs = cpu->pc++;

	return 0x00;
}

uint8_t IMP(CPU *cpu)
{
	cpu->fetched = cpu->acc;

	return 0x00;
}

uint8_t ZP0(CPU *cpu)
{
	cpu->addr_abs = cpu_fetch(cpu) & 0xFF;

	return 0x00;
}

uint8_t ZPY(CPU *cpu)
{
	cpu->addr_abs = (cpu_fetch(cpu) + cpu->y) & 0xFF;

	return 0x00;
}

uint8_t ZPX(CPU *cpu)
{
	cpu->addr_abs = (cpu_fetch(cpu) + cpu->x) & 0xFF;

	return 0x00;
}

uint8_t ABS(CPU *cpu)
{
	uint8_t lo = cpu_read_byte(cpu, cpu->pc++);
    uint8_t hi = cpu_read_byte(cpu, cpu->pc++);
    cpu->addr_abs = (hi << 8) | lo;

	return 0x00;
}

uint8_t ABX(CPU *cpu)
{
	uint8_t lo = cpu_fetch(cpu);
	uint8_t hi = cpu_fetch(cpu);

	cpu->addr_abs = ((hi << 8) | lo) + cpu->x;

	return 0x00;
}

uint8_t ABY(CPU *cpu)
{
	uint8_t lo = cpu_fetch(cpu);
	uint8_t hi = cpu_fetch(cpu);

	cpu->addr_abs = ((hi << 8) | lo) + cpu->y;

	return 0x00;
}

uint8_t REL(CPU *cpu)
{
	cpu->addr_rel = cpu_fetch(cpu);

	if (cpu->addr_rel & 0b10000000) {
		cpu->addr_rel |= 0xFF00;
	}

	return 0x00;
}
