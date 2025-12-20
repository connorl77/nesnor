#ifndef MEM_H
#define MEM_H

#define MEM_SIZE 1024

#include <stdint.h>

void memory_init(void);
void memory_free(void);

uint8_t read_byte(uint16_t address);
uint16_t read_word(uint16_t address);

void write_byte(uint16_t address, uint8_t value);
void write_word(uint16_t address, uint16_t value);

#endif
