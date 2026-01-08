#include "shell.h"

/**
 * main - Entry point
 * Return: Alaways 0
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		printf("$ ");  /* Display prompt */
        line = input_line(); /* Read input */
        if (!line)
            break; /* EOF */

        /* Skip empty lines */
        if (line[0] == '\0')
        {
            free(line);
            continue;
        }
        /* Tokenize */
        args = tokenize(line, " ");
        free(line);

        if (!args)
            continue;

        /* Execute the command */
		execute_command(args);

        /* Free tokenized args */
        free(args);
    }

    printf("\n");
    return 0;
}
