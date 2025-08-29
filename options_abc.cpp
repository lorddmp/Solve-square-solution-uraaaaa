#include "options_abc.h"

void options_abc(int argc, char *argv[])
{
    int n_root = -2;
    int opt = 0, option_index = 0;
    
    struct mas_upd abc_str = {};
    
    struct option options[] = {
    {"help", no_argument, NULL, 'h'},
    {"tests", no_argument, NULL, 't'},
    {"solve", no_argument, NULL, 's'},
    {"output", required_argument, NULL, 'o'},
    {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "htso:", options, &option_index)) != -1)
    {
    switch (opt)
    {
        case 'h':
            printf("This programme is intended to solve square equations.\n");
            printf("Accessible options:\n");
            printf("--help: outputs current message,\n");
            printf("--tests: runs programme tests,\n");
            printf("--solve: runs solving programme,\n");
            printf("--output: \033[31m(USE ONLY AFTER --solve) \033[37mrecords calculation results in the file (\033[31mWRITE ITS NAME AFTER THIS FLAG AND USE ONLY AFTER --solve)\033[37m.\n");
            printf("Good luck!\n");
            break;

        case 't':
            find_errors();
            break;

        case 's':
            input_abc(&abc_str);
            n_root = solve_eq(&abc_str);
            roots_print(n_root, &abc_str);
            break;

        case 'o':
            if(n_root == -2)
                printf("\033[31mIncorrect input, please enter flag --solve, then --output and then name of the file\n\033[37m");
            
            else
                {
                FILE *fp;
                fp = fopen(optarg, "w");
                roots_print_in_file(n_root, &abc_str, fp);
                fclose(fp);
                printf("Result is in file with name that you wrote\n");
                }
            break;

        case '?':
            printf("Wrong\n");
            break;
        
        default:
            printf("Unpredictable error hahaha\n");
    }
    }
}