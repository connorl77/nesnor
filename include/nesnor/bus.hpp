#pragma once
#include <array>
#include <cstdint>

class Bus
{

	private:
		std::array<std::uint8_t, 1000> *memory;

	public:
		Bus();
		~Bus();

		void set_memory(std::array<std::uint8_t, 1000> *ptr);
		std::array<std::uint8_t, 1000>* get_memory();

};
