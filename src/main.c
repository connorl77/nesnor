#include "bus.h"
#include "cpu.h"

#include <stdint.h>

int main(void)
{
	CPU cpu;
	Bus bus;

	bus_init(&bus);

	cpu.bus = &bus;

	cpu_init(&cpu);

	return 0;
}
