#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int run_assert_tests(void);
int run_io_mock_tests(void);

int main(void) {
    int total_failures =
            run_assert_tests() +
            run_io_mock_tests();

    if (total_failures == 0)
        print_message("\nOK - NO TEST FAILURES\n");
    else if (total_failures == 1)
        print_message("\nERROR, 1 TEST FAILED\n");
    else
        print_message("\nERROR, %i TESTS FAILED\n", total_failures);

    return total_failures;
}
