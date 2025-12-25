#include "bus.h"
#include <stdlib.h>

bool bus_init(Bus *bus, Cartridge *cartridge)
{
	if (bus == NULL)
	{
		return false;
	}

	bus->mem = malloc(sizeof(Memory));

	if (bus->mem->ram == NULL)
	{
		init_memory(bus->mem);
	}

	// should bus be responsible for initialising
	// the cartridge, or the caller?
	bus->cartridge = cartridge;

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

	cartridge_free(bus->cartridge);
	bus->cartridge = NULL;

	free(bus);
}

uint8_t bus_read_byte(Bus *bus, uint16_t address)
{
    if (address <= 0x1FFF) // RAM (0x0000 -> 0x1FFF)
    {
        return read_byte(bus->mem, address & 0x07FF);
    } 
    else if (address <= 0x3FFF) // PPU (0x2000 -> 0x3FFF)
    {
        return 0x00; 
    } 
    else if (address >= 0x4020)  // Cartridge (0x4020 -> 0xFFFF)
    {
        return cartridge_read(bus->cartridge, address);
    }

    return 0x00; // APU/IO and unmapped space
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
