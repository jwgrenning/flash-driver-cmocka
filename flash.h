#ifndef FLASH_INCLUDED
#define FLASH_INCLUDED

#include "io.h"

enum {
	FLASH_SUCCESS = 0
};

int flash_program(io_address offset, io_data data);

#endif
