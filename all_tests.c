#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

static void test_success(void **state) {
}

static const UnitTest tests[] = {
        unit_test(test_success),
};

int main(void) {
    return run_tests(tests);
}


