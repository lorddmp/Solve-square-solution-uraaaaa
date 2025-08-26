#include "test_abc.h"

void program_test(struct type_str_test str_test)
{
    int n_root = 0;

    n_root = solve_eq(&str_test.hahaha);
    if  (!((is_zero(str_test.hahaha.x1 - str_test.ans_x1) && is_zero(str_test.hahaha.x2- str_test.ans_x2) && n_root == str_test.n_roots_ans)))
    {
        txSetConsoleAttr(FOREGROUND_RED);
        printf("Error, wrong answer: x1 = %g (should be %g), x2 = %g (should be %g), n_roots = %d (should be %d)\n",
               str_test.hahaha.x1, str_test.ans_x1, str_test.hahaha.x2, str_test.ans_x2, n_root, str_test.n_roots_ans);
    }
}

//-----------------------------------------------------------------------------j

void find_errors()
{
    struct type_str_test str_test = {};

    FILE *fp = fopen("test_input.txt", "r");

    my_assert (fp == NULL);

    for (int i = 0; i<12; i++)
    {
        if (scan_struct(fp, &str_test) != 8)
            printf("ERROR");
        else
            program_test(str_test);
    }

    fclose(fp);
}

int scan_struct(FILE *fp, struct type_str_test *str_test)

{
    return (fscanf(fp, "%lg %lg %lg %lg %lg %lg %lg %d", &str_test->hahaha.a, &str_test->hahaha.b, &str_test->hahaha.c,
            &str_test->hahaha.x1, &str_test->hahaha.x2, &str_test->ans_x1, &str_test->ans_x2, &str_test->n_roots_ans));
}

//-----------------------------------------------------------------------------
void my_assert(bool exp)
{
    if (exp)
       abort();
}
