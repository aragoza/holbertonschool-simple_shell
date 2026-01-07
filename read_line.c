#include "shell.h"
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
 */

char *input_line(void)
{
    char *buffer = NULL;
    size_t len = 64;

    write(1, "$ ", 2);

    if (getline(&buffer, &len, stdin) == -1)
    {
        free(buffer);
        return (NULL);
    }

    return (buffer);
}
