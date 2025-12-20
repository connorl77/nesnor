#include "mem.h"

#include <stdio.h>
#include <stdlib.h>

static uint8_t *mem;

void memory_init(void)
{
	mem = (uint8_t*)malloc(MEM_SIZE * sizeof(uint8_t));	

	if (mem == NULL)
	{
		printf("Failed to allocate memory.\n");
	}
}

void memory_free(void)
{
	free(mem);
	mem = NULL;
}

void write_byte(uint16_t address, uint8_t val)
{
	mem[address] = val;
}

void write_word(uint16_t address, uint16_t val)
{
	mem[address] = val & 0xFF;
	mem[address + 1] = (val >> 8);
}

uint8_t read_byte(uint16_t address)
{
	return mem[address];
}

uint16_t read_word(uint16_t address)
{
	uint8_t lo = read_byte(address);
	uint8_t hi = read_byte(address + 1);

	return lo | (hi << 8);
}
