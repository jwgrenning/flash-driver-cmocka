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

static void test_mock_io_write_call_order(void **state) {
    expect_value(io_write, offset, 0xdead);
    expect_value(io_write, data, 0xbeef);
    expect_value(io_write, offset, 0xf00d);
    expect_value(io_write, data, 0x1dea);
    io_write(0xdead, 0xbeef);
    io_write(0xf00d, 0x1dea);
}

static void test_mock_order_between_mocks_ignores_call_order(void **state) {
    expect_value(io_write, offset, 0xdead);
    expect_value(io_write, data, 0xbeef);
    expect_value(io_read, offset, 0xdead);
    will_return(io_read, 0x42);
    io_read(0xdead);
    io_write(0xdead, 0xbeef);
}

static const UnitTest tests[] = {
    unit_test(test_mock_io_read),
    unit_test(test_mock_io_write),
    unit_test(test_mock_io_write_call_order),
    unit_test(test_mock_order_between_mocks_ignores_call_order),
};

int run_io_mock_tests() {
    print_message("\n============ starting %s\n", __FILE__);
    return run_tests(tests);
}



