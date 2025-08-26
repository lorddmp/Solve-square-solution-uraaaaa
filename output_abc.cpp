#include "output_abc.h"

int roots_print(int n_root, struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);
    double root_x1 = (*abc_str).x1, root_x2 = (*abc_str).x2;

    switch (n_root)
    {
    case ZERO_ROOTS:
        txSetConsoleAttr(FOREGROUND_RED);
        printf("There are no roots in the equation");
        break;

    case ONE_ROOT:
        txSetConsoleAttr(FOREGROUND_BLUE);
        printf("Root = %g", root_x1);
        break;

    case TWO_ROOTS:
        txSetConsoleAttr(FOREGROUND_LIGHTBLUE);
        printf("Root 1 = %g\nRoot 2 = %g", root_x1, root_x2);
        break;

    case INF_ROOTS:
        txSetConsoleAttr(FOREGROUND_MAGENTA);
        printf("-1");
        break;

    default:
        printf("Error");
    }
    return 0;
}
