#pragma once
#include <array>
#include <cstdint>

class Bus {
private:
  std::array<std::uint8_t, 1000> *memory;

public:
  Bus();
  ~Bus();

  void set_memory(std::array<std::uint8_t, 1000> *ptr);
  std::array<std::uint8_t, 1000> *get_memory();

  std::uint8_t read_byte(const std::uint16_t &address);
  std::uint16_t read_word(const std::uint16_t &address);

  void write_byte(const std::uint16_t &address, const std::uint8_t &data);
  void write_word(const std::uint16_t &address, const std::uint16_t &data);
};
