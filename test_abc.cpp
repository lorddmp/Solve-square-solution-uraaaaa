#include "test_abc.h"

#define NUM_OF_TESTS 12

void program_test(struct type_str_test str_test, int* n_right_tests)
{
    int n_root = 0;

    n_root = solve_eq(&str_test.type_mas_upd);
    if  (!((is_zero(str_test.type_mas_upd.x1 - str_test.ans_x1) && is_zero(str_test.type_mas_upd.x2- str_test.ans_x2) && n_root == str_test.n_roots_ans)))
        printf("\033[31mError, wrong answer: x1 = %g (should be %g), x2 = %g (should be %g), n_roots = %d (should be %d)\n\033[37m",
               str_test.type_mas_upd.x1,
               str_test.ans_x1,
               str_test.type_mas_upd.x2,
               str_test.ans_x2, n_root,
               str_test.n_roots_ans);
    else
        (*n_right_tests)++;

}

//-----------------------------------------------------------------------------

void find_errors()
{
    int n_right_tests = 0;
    struct type_str_test str_test = {};

    FILE *fp = fopen("./test_input.txt", "r");

    my_assert (fp == NULL);

    for (int i = 0; i < NUM_OF_TESTS; i++)
    {
        if (scan_struct(fp, &str_test) != 8)
            printf("\033[31mERROR\033[37m\n");
        else
            program_test(str_test, &n_right_tests);
    }

    fclose(fp);

    if (n_right_tests == NUM_OF_TESTS)
        printf("\033[32mAll tests have passed successfully\n\033[37m");
}

//-----------------------------------------------------------------------------

int scan_struct(FILE *fp, struct type_str_test *str_test)

{
    return (fscanf(fp, "%lg %lg %lg %lg %lg %lg %lg %d",
        &str_test->type_mas_upd.a,
        &str_test->type_mas_upd.b,
        &str_test->type_mas_upd.c,
        &str_test->type_mas_upd.x1,
        &str_test->type_mas_upd.x2,
        &str_test->ans_x1,
        &str_test->ans_x2,
        &str_test->n_roots_ans));
}

//-----------------------------------------------------------------------------

void my_assert(bool exp)
{
    if (exp)
       abort();
}
