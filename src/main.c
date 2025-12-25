#include "bus.h"
#include "cartridge.h"
#include "cpu.h"

#include <stdint.h>
#include <stdio.h>

int main(void)
{
	CPU cpu;
	Bus bus;
	Cartridge cartridge;

	if (!cartridge_init(&cartridge, "./6502_functional_test.bin"))
	{
		return 1;
	}

	if (!bus_init(&bus, &cartridge))
	{
		return 1;
	}

	cpu.bus = &bus;

	cpu_init(&cpu);

	return 0;
}
