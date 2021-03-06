#ifndef FLASH_INCLUDED
#define FLASH_INCLUDED

#include "io.h"

enum {
    FLASH_SUCCESS = 0,
    FLASH_VPP_ERROR,
    FLASH_PROGRAM_ERROR,
    FLASH_PROTECTED_BLOCK_ERROR,
    FLASH_INVALID_STATUS_ERROR,
};

int flash_program(io_address offset, io_data data);

#endif
