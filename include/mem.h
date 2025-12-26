#ifndef MEM_H
#define MEM_H

#include <stdbool.h>
#define MEM_SIZE 65536

#include <stdint.h>

uint8_t read_byte(uint8_t *mem, uint16_t address);
uint16_t read_word(uint8_t *mem, uint16_t address);

void write_byte(uint8_t *mem, uint16_t address, uint8_t value);
void write_word(uint8_t *mem, uint16_t address, uint16_t value);

#endif
