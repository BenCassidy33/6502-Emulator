#ifndef TESTS_H
#define TESTS_H

// clang-format off
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
// clang-format on

void test_env(void);
void test_string_split();

int run_unit_tests(void);

#endif // !TESTS_H
