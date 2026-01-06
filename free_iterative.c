#include "total.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 *
 *
 *
 */

void free_iteratively(char **argv)
{
    int i = 0;

    while (argv[i])
        free(argv[i++]);
    free(argv);
}
