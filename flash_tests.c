#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "flash.h"

static void expect_io_write(void **state, io_address addr, io_data data)
{
    expect_value(io_write, offset, addr);
    expect_value(io_write, data, data);
}

static void expect_enter_programming_mode(void **state)
{
    expect_io_write(state, 0, 0x40);
    expect_io_write(state, 0xdead, 0xbeef);
}

static void test_program_succeeds_ready_immediately(void **state) {
	expect_enter_programming_mode(state);
	expect_value(io_read, offset, 0);
    will_return(io_read, 1<<7);

    assert_int_equal(FLASH_SUCCESS, flash_program(0xdead, 0xbeef));
}

static const UnitTest tests[] = {
		unit_test(test_program_succeeds_ready_immediately),
};

int run_flash_tests() {
    print_message("\n============ starting %s\n", __FILE__);
    return run_tests(tests);
}

