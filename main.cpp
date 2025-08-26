#include "input_abc.h"
#include "solve_eq.h"
#include "output_abc.h"
#include "test_abc.h"
#include "structures.h"

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

// getopt(), argc, argv

int main(void)
{
    //argc, argv
    char decisive_letter;
    int n_root = 0;
    mas_upd abc_str = {};

    do
    {
    printf("Choose an option (t - test programme // s - solve your square equation: )");
    decisive_letter = getchar();
    clean_buff();
    if (decisive_letter == 't')
        find_errors();
    else if (decisive_letter == 's')
        {
        input_abc(&abc_str);
        n_root = solve_eq(&abc_str);//определение количества корней и их подсчет
        roots_print(n_root, &abc_str);//вывод ответа
        }
    else
        {
        txSetConsoleAttr(FOREGROUND_RED);
        printf("ERROR, choose between given letters!\n");
        txSetConsoleAttr(FOREGROUND_WHITE);
        continue;
        }
    printf("Now press 'e' to exit or any other button to continue: ");
    }
    while (decisive_letter!='e');
}



