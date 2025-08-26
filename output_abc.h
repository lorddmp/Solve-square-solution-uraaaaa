#ifndef OUTPUT_ABC
#define OUTPUT_ABC

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


int roots_print(int num_root, struct mas_upd *abc_str);

#endif
