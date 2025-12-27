#include "bus.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool bus_init(Bus *bus, Cartridge *cartridge)
{
	if (bus == NULL)
	{
		return false;
	}

	uint8_t mem[MEM_SIZE] = {0};

	for(int i = 0; i != MEM_SIZE; i++) 
	{
		mem[i] = 0x00;
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

	cartridge_free(bus->cartridge);
	bus->cartridge = NULL;

	free(bus);
}

#ifdef CPU_TEST_MODE
bool load_klaus_test(Bus *bus, const char *path)
{
    uint8_t buffer[0x10000];
    size_t size;

    if (!cartridge_init(path, buffer, &size))
	{
		printf("Cartridge failed to intiialise.");
        return false;
	}

    if (size > 0x10000)
	{
        return false;
	}

    memcpy(&bus->mem, buffer, size);

	bus->mem[0xFFFC] = 0x00;
	bus->mem[0xFFFD] = 0x04;

    return true;
}
#endif

uint8_t bus_read_byte(Bus *bus, uint16_t address)
{
#ifdef CPU_TEST_MODE
    return read_byte(bus->mem, address);
#else

    if ((address >= 0x0000 && address <= 0x07FF) ||
		(address >= 0x0800 && address <= 0x0FFF) ||
		(address >= 0x1000 && address <= 0x17FF) ||
		(address >= 0x1800 && address <= 0x1FFF)) // Internal RAM (0x0000 -> 0x07FF, mirrored)
    {
        return read_byte(bus->mem, address & 0x07FF);
    } 
    else if ((address >= 0x2000 && address <= 0x2007) ||
			(address >= 0x2008 && address <= 0x3FFF)) // PPU registers (0x2000 -> 0x2007, mirorred)
    {
        return 0x00 & 0x2007; 
    } 
    else if (address >= 0x4000 && address <= 0x4017) // APU and I/O (0x4000 -> 0x4017)
	{
		return 0x00;	
	}
    else if (address >= 0x4018 && address <= 0x401F) // Unused APU and I/O functions (0x4000 -> 0x4017)
	{
		return 0x00;
	}
    else if (address >= 0x4020 && address <= 0xFFFF)  // Cartridge (0x4020 -> 0xFFFF)
    {
        return cartridge_read(bus->cartridge, address);
    }

	return 0x00;
#endif
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
