#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>

#include "flash.h"

static void test_program_succeeds_ready_immediately(void **state) {

    expect_value(io_write, offset, 0);
    expect_value(io_write, data, 0x40);
    expect_value(io_write, offset, 0xdead);
    expect_value(io_write, data, 0xbeef);
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

