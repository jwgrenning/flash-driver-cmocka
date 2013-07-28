#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "io.h"

static void test_nothing(void **state) {
}

static const UnitTest tests[] = {
    unit_test(test_nothing),
};

int run_io_mock_tests() {
    return run_tests(tests);
}



