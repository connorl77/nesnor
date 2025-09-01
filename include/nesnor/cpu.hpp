#pragma once 
#include <cstdint>
#include "register.hpp"

class CPU
{
	private:
		std::uint16_t PC = 0x0000; // Program Counter
		std::uint8_t SP = 0x00; // Stack Pointer
		std::uint8_t ACC = 0x00; // Accumulator
		std::uint8_t IX = 0x00; // Index Register X
		std::uint8_t IY = 0x00; // Index Register Y
		std::uint8_t status = 0b00000000; // Status Register

	public:
		CPU();
		~CPU();

		std::uint8_t get_register(Register reg);
		void set_register(Register reg, std::uint8_t val);
};
