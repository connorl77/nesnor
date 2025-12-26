#include "bus.h"
#include "cartridge.h"
#include "cpu.h"

#include <stdint.h>
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	CPU cpu;
	Bus bus;
	Cartridge cartridge;

	uint8_t *buffer;
	size_t size;

	if (!cartridge_init("./6502_functional_test.bin", buffer, &size))
	{
		return 1;
	}

	if (!bus_init(&bus, &cartridge))
	{
		return 1;
	}

	cpu.bus = &bus;

	//cpu_init(&cpu);

#ifdef CPU_TEST_MODE
	
	if (!load_klaus_test(&bus, "./6502_functional_test.bin"))
	{
		printf("Failed to load test binary.");
		return 1;
	}
#endif

	cpu_init(&cpu);

	while (true)
	{
		printf("Result: 0x%X\n", cpu.pc);
		sleep(1);
		cpu_step(&cpu);
	}

	printf("%i", cartridge_read(&cartridge, 0xFFFC));

	return 0;
}
