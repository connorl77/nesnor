#ifndef	BUS_H
#define BUS_H

#include "cartridge.h"
#include "mem.h"

typedef struct {
	uint8_t mem[MEM_SIZE];
	Cartridge *cartridge;
} Bus;

bool bus_init(Bus *bus, Cartridge *cartridge);
void bus_free(Bus *bus);

#ifdef CPU_TEST_MODE
bool load_klaus_test(Bus *bus, const char *path);
#endif

uint8_t bus_read_byte(Bus *bus, uint16_t address);
uint16_t bus_read_word(Bus *bus, uint16_t address);

void bus_write_byte(Bus *bus, uint16_t address, uint8_t value);
void bus_write_word(Bus *bus, uint16_t address, uint16_t value);

#endif
