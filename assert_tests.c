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

static void test_set_asserts(void **state) {
    LargestIntegralType set[] = {10, 20, 30};
    int set_size = sizeof(set)/sizeof(LargestIntegralType);
    assert_int_equal(3, set_size);
    assert_in_set(10, set, set_size);
    assert_in_set(20, set, set_size);
    assert_in_set(30, set, set_size);
    assert_not_in_set(4, set, set_size);
}

static const UnitTest tests[] = {
        unit_test(test_simple_asserts),
        unit_test(test_set_asserts),
};

int run_assert_tests(void) {
    return run_tests(tests);
}



