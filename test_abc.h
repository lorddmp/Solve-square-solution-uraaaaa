#ifndef TEST_ABC
#define TEST_ABC

#include <stdio.h>
#include <stdlib.h>
#include "solve_eq.h"
#include "test_abc.h"
#include "structures.h"
#include "input_abc.h"

#define INF_ROOTS -1
#define ZERO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2

int scan_struct(FILE *fp, struct type_str_test *str_test);

void my_assert(bool exp);

void program_test(struct type_str_test str_test, int* n_right_tests);

void find_errors();

#endif
