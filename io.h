//- Copyright (c) 2008-20012 James Grenning
//- All rights reserved
//- For use by participants in James' training courses.

#ifndef IO_INCLUDED
#define IO_INCLUDED

#include <stdint.h>

typedef uint32_t io_address;
typedef uint16_t io_data;

io_data io_read(io_address offset);
void io_write(io_address offset, io_data data);

#endif
