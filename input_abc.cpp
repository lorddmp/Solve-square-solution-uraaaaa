#include "input_abc.h"

void scan(double *scan_num)
{
    my_assert(scan_num == NULL);
    
    bool ne_norm_koef = true;

    while(ne_norm_koef)
    {
        if (scanf("%lg", scan_num) != 1 || getchar() != '\n')
        {
            printf("\033[31mError, please enter any NUMBER\n");
            printf("Try again: \033[33m");
            clean_buff();
        }
        else
            ne_norm_koef = false;
    }
}

//-----------------------------------------------------------------------------

void input_abc(struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);

    double* koef_a = &abc_str->a, *koef_b = &abc_str->b, *koef_c = &abc_str->c;
    
    printf("\033[34mPlease enter coefficient a: \033[33m");
    scan(koef_a);
    
    printf("\033[34mPlease enter coefficient b: \033[33m");
    scan(koef_b);
    
    printf("\033[34mPlease enter coefficient c: \033[33m");
    scan(koef_c);
}

//-----------------------------------------------------------------------------

void clean_buff()
{
    while (getchar() != '\n');
}
