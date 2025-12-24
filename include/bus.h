#ifndef	BUS_H
#define BUS_H

#include "mem.h"

typedef struct {
	Memory *mem;
} Bus;

bool bus_init(Bus *bus);
void bus_free(Bus *bus);

uint8_t bus_read_byte(Bus *bus, uint16_t address);
uint16_t bus_read_word(Bus *bus, uint16_t address);

void bus_write_byte(Bus *bus, uint16_t address, uint8_t value);
void bus_write_word(Bus *bus, uint16_t address, uint16_t value);

#endif
