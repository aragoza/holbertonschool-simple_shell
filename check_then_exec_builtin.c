#include "shell.h"
#include <string.h>



int check_and_execute_builtin(char **args)
{
    int i;
    builtin_t builtins[] = {
        {NULL, NULL}
    };

    if (!args || !args[0])
        return 1; 


    for (i = 0; builtins[i].name != NULL; i++)
    {
        if (strcmp(args[0], builtins[i].name) == 0)
        {

            builtins[i].func(args);
            return 0; 
        }
    }

    return 1;
}
