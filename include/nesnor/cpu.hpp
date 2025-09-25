#pragma once
#include "instruction.hpp"
#include "instruction_identifier.hpp"
#include "nesnor/bus.hpp"
#include "register.hpp"
#include <cstdint>
#include <memory>
#include <unordered_map>

class CPU {
private:
  std::uint16_t PC = 0x0000;        // Program Counter
  std::uint8_t SP = 0x00;           // Stack Pointer
  std::uint8_t ACC = 0x00;          // Accumulator
  std::uint8_t IX = 0x00;           // Index Register X
  std::uint8_t IY = 0x00;           // Index Register Y
  std::uint8_t status = 0b00000000; // Status Register

  std::uint8_t opcode = 0x00;
  std::uint8_t cycles = 0;
  std::uint8_t fetched = 0x00;
  std::uint16_t addr_abs = 0x0000;
  std::uint16_t addr_rel = 0x0000;

  std::shared_ptr<Bus> bus;

public:
  CPU();
  ~CPU();

  std::shared_ptr<Bus> get_bus();
  void set_bus(std::shared_ptr<Bus> bus);

  std::uint8_t get_register(Register reg);
  void set_register(Register reg, std::uint8_t val);

  std::uint8_t fetch_byte();

  std::unordered_map<AddressingMode, std::function<std::uint8_t()>>
      addressing_mode_map = {{AddressingMode::IMM, std::bind(&CPU::IMM, this)},
                             {AddressingMode::ZPG, std::bind(&CPU::ZPG, this)},
                             {AddressingMode::ZPX, std::bind(&CPU::ZPX, this)},
                             {AddressingMode::ABS, std::bind(&CPU::ABS, this)},
                             {AddressingMode::ABX, std::bind(&CPU::ABX, this)},
                             {AddressingMode::ABY, std::bind(&CPU::ABY, this)},
                             {AddressingMode::INX, std::bind(&CPU::INX, this)},
                             {AddressingMode::INY, std::bind(&CPU::INY, this)}};

  std::unordered_map<InstructionIdentifier, std::function<std::uint8_t()>>
      instruction_map = {
          {InstructionIdentifier::ADC, std::bind(&CPU::ADC, this)}};

  // Addressing modes
  std::uint8_t ABS();
  std::uint8_t ABX();
  std::uint8_t ABY();
  std::uint8_t IND();
  std::uint8_t IZX();
  std::uint8_t IZY();
  std::uint8_t IMP();
  std::uint8_t IMM();
  std::uint8_t ZPG();
  std::uint8_t ZPX();
  std::uint8_t ZPY();
  std::uint8_t REL();

  // Instructions
  std::uint8_t ADC();
  std::uint8_t AND();
  std::uint8_t ASL();
  std::uint8_t BCC();
  std::uint8_t BCS();
  std::uint8_t BEQ();
  std::uint8_t BIT();
  std::uint8_t BMI();
  std::uint8_t BNE();
  std::uint8_t BPL();
  std::uint8_t BRK();
  std::uint8_t BVC();
  std::uint8_t BVS();
  std::uint8_t CLC();
  std::uint8_t CLD();
  std::uint8_t CLI();
  std::uint8_t CLV();
  std::uint8_t CMP();
  std::uint8_t CPX();
  std::uint8_t CPY();
  std::uint8_t DEC();
  std::uint8_t DEX();
  std::uint8_t DEY();
  std::uint8_t EOR();
  std::uint8_t INC();
  std::uint8_t INX();
  std::uint8_t INY();
  std::uint8_t JMP();
  std::uint8_t JSR();
  std::uint8_t LDA();
  std::uint8_t LDX();
  std::uint8_t LDY();
  std::uint8_t LSR();
  std::uint8_t NOP();
  std::uint8_t ORA();
  std::uint8_t PHA();
  std::uint8_t PHP();
  std::uint8_t PLA();
  std::uint8_t PLP();
  std::uint8_t ROL();
  std::uint8_t ROR();
  std::uint8_t RTI();
  std::uint8_t RTS();
  std::uint8_t SBC();
  std::uint8_t SEC();
  std::uint8_t SED();
  std::uint8_t SEI();
  std::uint8_t STA();
  std::uint8_t STX();
  std::uint8_t STY();
  std::uint8_t TAX();
  std::uint8_t TAY();
  std::uint8_t TSX();
  std::uint8_t TXA();
  std::uint8_t TXS();
  std::uint8_t TYA();

  std::uint8_t ILL(); // illegal instruction

  // Other operations
  void IRQ();
  void NMI();
};
