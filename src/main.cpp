#include <iostream>
#include <memory>

#include "nesnor/bus.hpp"
#include "nesnor/cpu.hpp"

int main(int argc, char **argv)
{
	std::array<std::uint8_t, 1000> memory;
	memory.fill(0x11);

	CPU cpu;
	Bus bus;

	bus.set_memory(&memory);

	return EXIT_SUCCESS;
}
