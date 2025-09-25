#include <memory>
#include <vector>

#include "nesnor/bus.hpp"
#include "nesnor/cpu.hpp"
#include "nesnor/instruction.hpp"

int main(int argc, char **argv)
{
	std::vector<Instruction> instructions;

	std::array<std::uint8_t, 1000> memory;
	memory.fill(0x11);

	CPU cpu;
	std::shared_ptr<Bus> bus = std::make_shared<Bus>();

	bus->set_memory(&memory);
	cpu.set_bus(bus);

	return EXIT_SUCCESS;
}
