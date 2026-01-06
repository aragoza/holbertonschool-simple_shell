#include "total.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *
 *
 *
 *
 *
 *
 *
 *
*/

char *wait_for_line(void)
{
    char *buffer = NULL;
    size_t len = 0;

    write(1, "$ ", 2);

    if (getline(&buffer, &len, stdin) == -1)
    {
        free(buffer);
        return (NULL);
    }

    return (buffer);
}
