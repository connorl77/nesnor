#include "bus.h"
#include "mem.h"
#include <stdlib.h>

bool bus_init(Bus *bus)
{
	bus->mem = malloc(sizeof(Memory));

	if (bus->mem->ram == NULL)
	{
		init_memory(bus->mem);
	}

	return true;
}

void bus_free(Bus *bus)
{
	if (bus == NULL)
	{
		return;
	}

	free_memory(bus->mem);
	bus->mem = NULL;

	free(bus);
}

uint8_t bus_read_byte(Bus *bus, uint16_t address)
{
	if (address >= 0x0000 && address <= 0x1FFF) {
        return read_byte(bus->mem, address & 0x07FF);
    } 

	return read_byte(bus->mem, address);
}

uint16_t bus_read_word(Bus *bus, uint16_t address)
{
	// Switch to use bus_read, this'll handle address
	// mapping between RAM/PPU/Cartridge.
	return read_word(bus->mem, address);
}

void bus_write_byte(Bus *bus, uint16_t address, uint8_t value)
{
	write_byte(bus->mem, address, value);
}

void bus_write_word(Bus *bus, uint16_t address, uint16_t value)
{
	write_word(bus->mem, address, value);
}
