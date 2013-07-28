#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>

#include "flash.h"

static void test_nothing(void **state) {
}

static const UnitTest tests[] = {
        unit_test(test_nothing),
};

int run_flash_tests() {
    return run_tests(tests);
}

