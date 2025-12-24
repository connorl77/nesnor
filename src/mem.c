#include "mem.h"

#include <stdbool.h>
#include <stdlib.h>

bool init_memory(Memory *mem)
{
	if (mem == NULL)
	{
		return false;
	}

	mem->ram = (uint8_t*)malloc(MEM_SIZE * sizeof(uint8_t));	

	return mem != NULL;
}

void free_memory(Memory *mem)
{
	free(mem->ram);
	mem->ram = NULL;
	free(mem);
}

void write_byte(Memory *mem, uint16_t address, uint8_t val)
{
	mem->ram[address] = val;
}

void write_word(Memory *mem, uint16_t address, uint16_t val)
{
	mem->ram[address] = val & 0xFF;
	mem->ram[address + 1] = (val >> 8);
}

uint8_t read_byte(Memory *mem, uint16_t address)
{
	return mem->ram[address];
}

uint16_t read_word(Memory *mem, uint16_t address)
{
	uint8_t lo = read_byte(mem, address);
	uint8_t hi = read_byte(mem, address + 1);

	return lo | (hi << 8);
}
