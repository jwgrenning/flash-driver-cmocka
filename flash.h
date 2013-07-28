#ifndef FLASH_INCLUDED
#define FLASH_INCLUDED

#include "io.h"

int flash_program(io_address offset, io_data data);

#endif
