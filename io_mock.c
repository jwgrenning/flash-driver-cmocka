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

static void test_mock_io_read(void **state) {
    expect_value(io_read, offset, 0xdead);
    will_return(io_read, 0x42);
    assert_int_equal(0x42, io_read(0xdead));
}

static const UnitTest tests[] = {
    unit_test(test_mock_io_read),
};

int run_io_mock_tests() {
    return run_tests(tests);
}



