#pragma once
#include <cstdint>
#include <functional>
#include "addressing_mode.hpp"

struct Instruction
{
	std::uint8_t op_code;
	AddressingMode addr_mode;
	std::uint8_t bytes;
	std::uint8_t cycles;
	std::function<int()> execute;	
};
