#include "solve_eq.h"

int solve_eq(struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);
    double koef_a = (*abc_str).a, koef_b = (*abc_str).b,koef_c = (*abc_str).c;

    if (is_zero(koef_a))
        return koef_a_zero(abc_str);//разбор случаев с а=0

    double disc = koef_b*koef_b - 4*koef_a*koef_c;

    if (is_zero(disc))
        return disc_zero(abc_str);//дискриминант равен 0, функция считает корень
    else
    {
        if (disc > 0)
            return disc_one(disc, abc_str);//дискриминант больше 0, функция считает корни
        else
            return ZERO_ROOTS;//дискриминант меньше 0
    }
}

//-----------------------------------------------------------------------------

int koef_a_zero(struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);
    double koef_b = (*abc_str).b,koef_c = (*abc_str).c;

    if (is_zero(koef_b))
    {
        if (is_zero(koef_c))
            return INF_ROOTS;
        else
            return ZERO_ROOTS;
    }
    else
        return (lin_eq(abc_str));
}

//-----------------------------------------------------------------------------

int lin_eq(struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);

    double koef_b = (*abc_str).b,koef_c = (*abc_str).c, *root_x1 = &(*abc_str).x1;

    if (is_zero(koef_c))
        *root_x1 = 0;
    else
        *root_x1 = -koef_c/koef_b;
    return ONE_ROOT;
}

//-----------------------------------------------------------------------------

bool is_zero(double maybe_zero)
{
    return (fabs(maybe_zero) < 1e-9);
}

//-----------------------------------------------------------------------------

int disc_zero(struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);

    double koef_a = (*abc_str).a, koef_b = (*abc_str).b, *root_x1 = &(*abc_str).x1;

    if (is_zero(koef_b))
        *root_x1 = 0;
    else
        *root_x1 = -koef_b/(2 * koef_a);
    return ONE_ROOT;
}

//-----------------------------------------------------------------------------

int disc_one(double disc, struct mas_upd *abc_str)
{
    my_assert(abc_str == NULL);


    double koef_a = (*abc_str).a, koef_b = (*abc_str).b, *root_x1 = &(*abc_str).x1, *root_x2 = &(*abc_str).x2;

    *root_x1 = (-koef_b + sqrt(disc))/2.0/koef_a;
    *root_x2 = (-koef_b - sqrt(disc))/2.0/koef_a;

    return TWO_ROOTS;
}

//-----------------------------------------------------------------------------
void clean_buff()
{
    while (getchar() != '\n');
}


