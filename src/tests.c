// clang-format off
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
// clang-format on

static void test_env(void **state) {
	size_t x = 5;
	assert_int_equal(x, 5);
};

static void test_string_split(void **state) {};

int run_unit_tests(void) {
	const struct CMUnitTest tests[] = {cmocka_unit_test(test_env)};

	return cmocka_run_group_tests(tests, NULL, NULL);
};
