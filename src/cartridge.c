#include "cartridge.h"
#include <stdio.h>
#include <stdlib.h>

bool cartridge_init(Cartridge *cartridge, const char *file_path)
{
	cartridge->name = "Test Cartridge";

	FILE *fptr = fopen(file_path, "r");

	if (fptr == NULL)
	{
		printf("Failed to open file '%s'.", file_path);
		return false;
	}

	fread(cartridge->data, 1, MAX_CARTRIDGE_SIZE, fptr);

	fclose(fptr);
	return true;
}

void cartridge_free(Cartridge *cartridge)
{
	if (cartridge == NULL)
	{
		return;
	}

	free(cartridge);
}


uint8_t cartridge_read(Cartridge *cartridge, uint16_t address)
{
	return cartridge->data[address];
}
