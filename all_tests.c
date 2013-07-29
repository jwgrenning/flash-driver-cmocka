#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int run_assert_tests(void);
int run_io_mock_tests(void);
int run_flash_tests(void);

int main(void) {
    int total_failures =
            run_assert_tests() +
            run_flash_tests() +
            run_io_mock_tests();

    print_message("\n============ Summary %s\n", __FILE__);
   if (total_failures == 0)
        print_message("OK - NO TEST FAILURES\n");
    else if (total_failures == 1)
        print_message("ERROR, 1 TEST FAILED\n");
    else
        print_message("ERROR, %i TESTS FAILED\n", total_failures);

    return total_failures;
}
