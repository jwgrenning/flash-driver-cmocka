#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "io.h"

io_data io_read(io_address offset)
{
    check_expected(offset);
    return (int)mock();
}

void  io_write(io_address offset, io_data data)
{
    check_expected(offset);
    check_expected(data);
}

static void test_mock_io_read(void **state) {
    expect_value(io_read, offset, 0xdead);
    will_return(io_read, 0x42);
    assert_int_equal(0x42, io_read(0xdead));
}

static void test_mock_io_write(void **state) {
    expect_value(io_write, offset, 0xdead);
    expect_value(io_write, data, 0xbeef);
    io_write(0xdead, 0xbeef);
}

static const UnitTest tests[] = {
    unit_test(test_mock_io_read),
    unit_test(test_mock_io_write),
};

int run_io_mock_tests() {
    return run_tests(tests);
}



