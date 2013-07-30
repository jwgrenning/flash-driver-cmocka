flash-dirver-cmocka
===================

Example of using cmocka c test framework, and TDD

First install ccmocka from cmocka.org
You also need cmake and gcc

At the time of this writing, here is what I did
- Download the tarball
- Expand it into <some_dir>
- mkdir <some_dir>/build
- cd <some_dir>/build
cmake ..
make
make install

If you use eclipse, you may want to notice where it puts the .h files so you can tell eclipse.

Objective
===================

Test-drive a flash memory driver using cmocka.  The spec for flash_program is the flowchart found in flash-program-flow-chart.pdf.  Look at io_mock.c to see how to unit test a driver that interacts with hardware through io_read() and io_wite().


Thanks
===================
Thanks to STMicroelectronics for letting me use their device and specifications in my book: Test-Driven Development for Embedded C.
