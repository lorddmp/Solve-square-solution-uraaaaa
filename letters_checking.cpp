#include "letters_checking.h"
void letters_checking()
{
int n_root = 0;
struct mas_upd abc_str = {};
int decisive_letter;
do
    {
    printf("Choose an option t (test programme) // s (solve your square equation) // e (exit programme): ");
    decisive_letter = getchar();
    if (decisive_letter == '\n')
        {
        txSetConsoleAttr(FOREGROUND_RED);
        printf("ERROR, choose between given letters!\n");
        txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
        continue;
        }
    if (getchar() != '\n')
        {
        txSetConsoleAttr(FOREGROUND_RED);
        printf("ERROR, choose between given letters!\n");
        txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
        clean_buff();
        continue;
        }

    if (decisive_letter == 't')
        {
        find_errors();
        txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
        }
    else if (decisive_letter == 's')
        {
        input_abc(&abc_str);
        n_root = solve_eq(&abc_str);//определение количества корней и их подсчет
        roots_print(n_root, &abc_str);//вывод ответа
        txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
        }
    else if (decisive_letter == 'e');

    else
        {
        txSetConsoleAttr(FOREGROUND_RED);
        printf("ERROR, choose between given letters!\n");
        txSetConsoleAttr(FOREGROUND_LIGHTGRAY);
        continue;
        }
    }
    while (decisive_letter!='e');
}
