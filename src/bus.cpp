#include "nesnor/bus.hpp"

Bus::Bus()
{

}

Bus::~Bus()
{

}

void Bus::set_memory(std::array<std::uint8_t, 1000> *ptr)
{
	memory = ptr;
}

std::array<std::uint8_t, 1000>* Bus::get_memory()
{
	return memory;
}
