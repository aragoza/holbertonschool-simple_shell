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
    size_t bufsize = 0;

    if (getline(&buffer, &bufsize, stdin) == -1)
    {
        free(buffer);
        return NULL; /* EOF or error */
    }

    /* Remove trailing newline */
    if (buffer[0] != '\0')
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }

    return buffer;
}
