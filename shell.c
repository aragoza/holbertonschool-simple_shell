#include "shell.h"

/**
 * main - launch the loop of the shell with no error
 *
 * Return: 0 when the loop ends
 */

int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		printf("$ ");  /* Display prompt */
		/* Read input */
		line = input_line();
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
		free_iteratively(args);
	}

	printf("\n");
	return (0);
}
