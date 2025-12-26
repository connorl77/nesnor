#include "cartridge.h"
#include <stdio.h>
#include <stdlib.h>

bool cartridge_init(const char *file_path, uint8_t *buff, size_t *out_size)
{
	FILE *f = fopen(file_path, "rb");
    if (!f) 
	{
		return false;
	}

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    if (size <= 0 || size > 0x10000) {
        fclose(f);
        return false;
    }

    fread(buff, 1, size, f);
    fclose(f);

    *out_size = (size_t)size;
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
