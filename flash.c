#include "flash.h"

int flash_program(io_address addr, io_data data)
{
	io_write(0, 0x40);
	io_write(addr, data);
	io_read(0);
    return 0;
}
