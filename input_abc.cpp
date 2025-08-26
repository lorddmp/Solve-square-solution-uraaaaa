#include "input_abc.h"

void scan(double *scan_num)
{
    my_assert(scan_num == NULL);

    txSetConsoleAttr(FOREGROUND_YELLOW);

    while (scanf("%lg", scan_num) != 1)
        {
            clean_buff();

            txSetConsoleAttr(FOREGROUND_RED);
            printf( "Error, please enter any NUMBER ");
            txSetConsoleAttr(FOREGROUND_YELLOW);
        }
    clean_buff();
}

//-----------------------------------------------------------------------------

void input_abc(struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);

    double* koef_a = &abc_str->a, *koef_b = &abc_str->b, *koef_c = &abc_str->c;

    txSetConsoleAttr(FOREGROUND_LIGHTCYAN);
    printf("Please enter coefficient a: ");
    scan(koef_a);

    txSetConsoleAttr(FOREGROUND_LIGHTCYAN);
    printf("Please enter coefficient b: ");
    scan(koef_b);

    txSetConsoleAttr(FOREGROUND_LIGHTCYAN);
    printf("Please enter coefficient c: ");
    scan(koef_c);
}

