#ifndef MEM_H
#define MEM_H

#include <stdbool.h>
#define MEM_SIZE 1024

#include <stdint.h>

typedef struct {
	uint8_t *ram;
} Memory;

bool init_memory(Memory *mem);
void free_memory(Memory *mem);

uint8_t read_byte(Memory *mem, uint16_t address);
uint16_t read_word(Memory *mem, uint16_t address);

void write_byte(Memory *mem, uint16_t address, uint8_t value);
void write_word(Memory *mem, uint16_t address, uint16_t value);

#endif
