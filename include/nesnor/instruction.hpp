#pragma once

class Instruction
{
	private:
		short cycles = 0;
	public:
		std::function execute;	

};
