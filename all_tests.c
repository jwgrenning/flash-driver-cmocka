#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>

static void test_simple_asserts(void **state) {
    assert_false(false);
    assert_in_range(10, 9, 11);
    assert_int_equal(99, 99);
    assert_int_not_equal(42, 43);
    assert_memory_equal("this", "this", 4);
    assert_memory_not_equal("this", "that", 4);
    assert_non_null(test_simple_asserts);
    assert_not_in_range(999, 1, 100);
    assert_null(NULL);
    assert_string_equal("hey", "hey");
    assert_string_not_equal("hey", "hay");
    assert_true(true);
}

static const UnitTest tests[] = {
        unit_test(test_simple_asserts),
};

int main(void) {
    return run_tests(tests);
}


