#ifndef SOLVE_EQ
#define SOLVE_EQ

#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include "solve_eq.h"
#include "test_abc.h"
#include "structures.h"

#define INF_ROOTS -1
#define ZERO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2

int solve_eq(struct mas_upd *abc_str);

int koef_a_zero(struct mas_upd *abc_str);

int lin_eq(struct mas_upd *abc_str);

bool is_zero(double maybe_zero);

int disc_zero(struct mas_upd *abc_str);

int disc_one(double disc, struct mas_upd *abc_str);

void clean_buff();

#endif
