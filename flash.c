#include "flash.h"

enum {
    readyBit = 0x80,
    vppErrorBit = 0x08,
    programErrorBit = 0x10,
    protectedBlockErrorBit = 0x02
};

enum {
	reset = 0xff, program = 0x40
};

int flash_program(io_address addr, io_data data)
{
    int status = 0;

    io_write(0, program);
    io_write(addr, data);

    while ((status & readyBit) == 0)
        status = io_read(0);

    if (status == readyBit)
    	return FLASH_SUCCESS;

    io_write(0, reset);
    if (status & vppErrorBit)
    	return FLASH_VPP_ERROR;
    else if (status & programErrorBit)
    	return FLASH_PROGRAM_ERROR;
    else if (status & protectedBlockErrorBit)
    	return FLASH_PROTECTED_BLOCK_ERROR;

    return -1;

}
