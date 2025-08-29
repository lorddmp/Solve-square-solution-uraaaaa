#include "letters_checking.h"

void letters_checking()
{
    int n_root = 0;
    int decisive_letter;
    
    struct mas_upd abc_str = {};
    
    do
        {
        printf("Choose an option t (test programme) // s (solve your square equation) // e (exit programme): ");
        
        decisive_letter = getchar();
        if (decisive_letter == '\n')
            {
            printf("\033[31mERROR, choose between given letters!\033[37m\n");
            continue;
            }
        if (getchar() != '\n')
            {
            printf("\033[31mERROR, choose between given letters!\033[37m\n");
            clean_buff();
            continue;
            }
    
        if (decisive_letter == 't')
            find_errors();
        
        else if (decisive_letter == 's')
            {
            input_abc(&abc_str);
            n_root = solve_eq(&abc_str);
            roots_print(n_root, &abc_str);
            }
        else if (decisive_letter == 'e');
    
        else
            {
            printf("\033[31mERROR, choose between given letters!\033[37m\n");
            continue;
            }
        }
        while (decisive_letter!='e');
        
        printf ("\033[32mProgramme finished successfully\033[37m\n");
}
