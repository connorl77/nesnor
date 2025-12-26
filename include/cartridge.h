#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_CARTRIDGE_SIZE 128000

typedef struct
{
	size_t size;
	uint8_t data[];
} Cartridge;

bool cartridge_init(const char *file_path, uint8_t *buff, size_t *out_size);
void cartridge_free(Cartridge *cartridge);

uint8_t cartridge_read(Cartridge *cartridge, uint16_t address);

#endif
