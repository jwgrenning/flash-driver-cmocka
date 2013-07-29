#include "flash.h"

enum {
    readyBit=0x80
};

int flash_program(io_address addr, io_data data)
{
    int status = 0;

    io_write(0, 0x40);
    io_write(addr, data);

    while ((status & readyBit) == 0)
        status = io_read(0);

    return FLASH_SUCCESS;
}
