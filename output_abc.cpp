#include "output_abc.h"

int roots_print(int n_root, struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);
    
    double root_x1 = (*abc_str).x1, root_x2 = (*abc_str).x2;

    switch (n_root)
    {
    case ZERO_ROOTS:
        printf("\033[31mThere are no roots in the equation\n\033[37m");
        break;

    case ONE_ROOT:
        printf("\033[35mRoot = %g\n\033[37m", root_x1);
        break;

    case TWO_ROOTS:
        printf("\033[32mRoot 1 = %g\nRoot 2 = %g\n\033[37m", root_x1, root_x2);
        break;

    case INF_ROOTS:
        printf("-1\n\033[37m");
        break;

    default:
        printf("\033[33mError\n\033[37m");
    }
    return 0;
}

//----------------------------------------------------------------------

int roots_print_in_file(int n_root, struct mas_upd *abc_str, FILE* fp)
{
    my_assert(abc_str == NULL);
    my_assert(fp == NULL);
    
    double root_x1 = (*abc_str).x1, root_x2 = (*abc_str).x2;

    switch (n_root)
    {
    case ZERO_ROOTS:
        fprintf(fp, "There are no roots in the equation\n");
        break;

    case ONE_ROOT:
        fprintf(fp, "Root = %g\n", root_x1);
        break;

    case TWO_ROOTS:
        fprintf(fp, "Root 1 = %g\nRoot 2 = %g\n", root_x1, root_x2);
        break;

    case INF_ROOTS:
        fprintf(fp, "-1\n");
        break;

    default:
        fprintf(fp, "Error\n");
    }
    return 0;
}
