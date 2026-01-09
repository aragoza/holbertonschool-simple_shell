#include "shell.h"

int shell_non_interactive(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        /* Remove newline character */
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        /* Skip empty lines */
        if (line[0] == '\0')
            continue;

        /* Tokenize */
        args = tokenize(line, " ");
        if (!args)
            continue;

        /* Execute the command */
        execute_command(args);

        /* Free tokenized args */
        free_iteratively(args);
    }

    free(line);

    return (0);
}
