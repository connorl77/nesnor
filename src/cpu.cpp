#include "nesnor/cpu.hpp"

CPU::CPU()
{

}

CPU::~CPU()
{

}

std::uint8_t CPU::get_register(Register reg)
{
	switch (reg)
	{
		case Register::IX:
			return IX;
		case Register::IY:
			return IY;
		case Register::SP:
			return SP;

		default:
			return 0x00;
	}
}

void CPU::set_register(Register reg, const std::uint8_t val)
{
	switch (reg)
	{
		case Register::IX:
			IX = val;
			break;
		case Register::IY:
			IY = val;
			break;
		case Register::SP:
			SP = val;
			break;

		default:
			break;
	}
}
