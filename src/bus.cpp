#include "nesnor/bus.hpp"

Bus::Bus()

{}

Bus::~Bus() {}

void Bus::set_memory(std::array<std::uint8_t, 1000> *ptr) { memory = ptr; }

std::array<std::uint8_t, 1000> *Bus::get_memory() { return memory; }

std::uint8_t Bus::read_byte(const std::uint16_t &address) {
  std::uint8_t data = (*memory)[address];

  return data;
}

std::uint16_t Bus::read_word(const std::uint16_t &address) {
  std::uint8_t lo = read_byte(address);
  std::uint8_t hi = read_byte(address + 1);

  std::uint16_t data = lo | (hi << 8);

  return data;
}

void Bus::write_byte(const std::uint16_t &address, const std::uint8_t &data) {
  (*memory)[address] = data;
}

void Bus::write_word(const std::uint16_t &address, const std::uint16_t &data) {
  std::uint8_t lo = data & 0x00FF;
  std::uint8_t hi = (data >> 8) & 0x00FF;

  write_byte(address, lo);
  write_byte(address + 1, hi);
}
