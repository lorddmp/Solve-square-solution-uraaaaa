#include <stdlib.h>
#include <getopt.h>
#include "input_abc.h"
#include "solve_eq.h"
#include "output_abc.h"
#include "test_abc.h"
#include "structures.h"

//WSL

//{----------------------------------------------------------------------------
//!
//! solves a square equation with  God's help
//!
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots
//!       returns -1
//}----------------------------------------------------------------------------



int main(int argc, char *argv[])
{
    int n_root = 0;
    struct mas_upd abc_str = {};
    struct option options[]=
    {
    {"help", no_argument, NULL, 'h'},
    {"tests", no_argument, NULL, 't'},
    {"solve", no_argument, NULL, 's'},
    {0, 0, 0, 0}
    };
    int opt = 0;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "hts", options, &option_index)) != -1)



//-----------------------------------------------------------------------------

    {
    switch (opt)
    {
        case 'h':
            printf("This programme is intended to solve square equations.\n");
            printf("Accessible options:\n--help output current message,\n");
            printf("--tests run programme tests,\n");
            printf("--solve starts solving programme.\n");
            printf("Good luck!");
            break;
        case 't':
            find_errors();
            txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
            break;
        case 's':
            input_abc(&abc_str);
            n_root = solve_eq(&abc_str);//определение количества корней и их подсчет
            roots_print(n_root, &abc_str);//вывод ответа
            txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
            break;
        case '?':
            printf("You are goddamn wrong");
            break;
        default:
            printf("Unpredictable error hahaha");
    }
    }
    txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
    return 0;
}



