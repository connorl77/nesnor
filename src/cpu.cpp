#include "nesnor/cpu.hpp"

CPU::CPU() {}

CPU::~CPU() {}

std::shared_ptr<Bus> CPU::get_bus() { return this->bus; }

void CPU::set_bus(std::shared_ptr<Bus> bus) { this->bus = bus; }

std::uint8_t CPU::get_register(Register reg) {
  switch (reg) {
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

void CPU::set_register(Register reg, const std::uint8_t val) {
  switch (reg) {
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

std::uint8_t CPU::fetch_byte() {
  std::uint8_t data = bus->read_byte(PC);
  this->PC++;

  return data;
}

std::uint8_t CPU::ABS() {
  std::uint8_t lo = fetch_byte();
  std::uint8_t hi = fetch_byte();

  addr_abs = (hi << 8) | lo;

  return 0;
}

std::uint8_t CPU::ABX() { return 0; }
std::uint8_t CPU::ABY() { return 0; }
std::uint8_t CPU::IND() { return 0; }
std::uint8_t CPU::IZX() { return 0; }
std::uint8_t CPU::IZY() { return 0; }
std::uint8_t CPU::IMP() { return 0; }
std::uint8_t CPU::IMM() { return 0; }
std::uint8_t CPU::ZPG() { return 0; }
std::uint8_t CPU::ZPX() { return 0; }
std::uint8_t CPU::ZPY() { return 0; }
std::uint8_t CPU::REL() { return 0; }

// Instructions
std::uint8_t CPU::ADC() { return 0; }
std::uint8_t CPU::AND() { return 0; }
std::uint8_t CPU::ASL() { return 0; }
std::uint8_t CPU::BCC() { return 0; }
std::uint8_t CPU::BCS() { return 0; }
std::uint8_t CPU::BEQ() { return 0; }
std::uint8_t CPU::BIT() { return 0; }
std::uint8_t CPU::BMI() { return 0; }
std::uint8_t CPU::BNE() { return 0; }
std::uint8_t CPU::BPL() { return 0; }
std::uint8_t CPU::BRK() { return 0; }
std::uint8_t CPU::BVC() { return 0; }
std::uint8_t CPU::BVS() { return 0; }
std::uint8_t CPU::CLC() { return 0; }
std::uint8_t CPU::CLD() { return 0; }
std::uint8_t CPU::CLI() { return 0; }
std::uint8_t CPU::CLV() { return 0; }
std::uint8_t CPU::CMP() { return 0; }
std::uint8_t CPU::CPX() { return 0; }
std::uint8_t CPU::CPY() { return 0; }
std::uint8_t CPU::DEC() { return 0; }
std::uint8_t CPU::DEX() { return 0; }
std::uint8_t CPU::DEY() { return 0; }
std::uint8_t CPU::EOR() { return 0; }
std::uint8_t CPU::INC() { return 0; }
std::uint8_t CPU::INX() { return 0; }
std::uint8_t CPU::INY() { return 0; }
std::uint8_t CPU::JMP() { return 0; }
std::uint8_t CPU::JSR() { return 0; }
std::uint8_t CPU::LDA() { return 0; }
std::uint8_t CPU::LDX() { return 0; }
std::uint8_t CPU::LDY() { return 0; }
std::uint8_t CPU::LSR() { return 0; }
std::uint8_t CPU::NOP() { return 0; }
std::uint8_t CPU::ORA() { return 0; }
std::uint8_t CPU::PHA() { return 0; }
std::uint8_t CPU::PHP() { return 0; }
std::uint8_t CPU::PLA() { return 0; }
std::uint8_t CPU::PLP() { return 0; }
std::uint8_t CPU::ROL() { return 0; }
std::uint8_t CPU::ROR() { return 0; }
std::uint8_t CPU::RTI() { return 0; }
std::uint8_t CPU::RTS() { return 0; }
std::uint8_t CPU::SBC() { return 0; }
std::uint8_t CPU::SEC() { return 0; }
std::uint8_t CPU::SED() { return 0; }
std::uint8_t CPU::SEI() { return 0; }
std::uint8_t CPU::STA() { return 0; }
std::uint8_t CPU::STX() { return 0; }
std::uint8_t CPU::STY() { return 0; }
std::uint8_t CPU::TAX() { return 0; }
std::uint8_t CPU::TAY() { return 0; }
std::uint8_t CPU::TSX() { return 0; }
std::uint8_t CPU::TXA() { return 0; }
std::uint8_t CPU::TXS() { return 0; }
std::uint8_t CPU::TYA() { return 0; }

std::uint8_t CPU::ILL() { return 0; } // illegal instruction

// Other operations
void IRQ() {}
void NMI() {}
