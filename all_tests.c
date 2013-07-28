#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int run_assert_tests(void);
int run_io_mock_tests(void);

int main(void) {
    return  run_io_mock_tests()
            + run_assert_tests();
}


