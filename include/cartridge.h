#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_CARTRIDGE_SIZE 128000

typedef struct
{
	const char *name;
	uint8_t data[MAX_CARTRIDGE_SIZE];
} Cartridge;

bool cartridge_init(Cartridge *cartridge, const char *file_path);
void cartridge_free(Cartridge *cartridge);

uint8_t cartridge_read(Cartridge *cartridge, uint16_t address);

#endif
