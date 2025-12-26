#include "mem.h"

#include <stdbool.h>

void write_byte(uint8_t *mem, uint16_t address, uint8_t val)
{
	mem[address] = val;
}

void write_word(uint8_t *mem, uint16_t address, uint16_t val)
{
	mem[address] = val & 0xFF;
	mem[address + 1] = (val >> 8);
}

uint8_t read_byte(uint8_t *mem, uint16_t address)
{
	return mem[address];
}

uint16_t read_word(uint8_t *mem, uint16_t address)
{
	uint8_t lo = read_byte(mem, address);
	uint8_t hi = read_byte(mem, address + 1);

	return lo | (hi << 8);
}
