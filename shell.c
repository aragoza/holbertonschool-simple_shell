#include "shell.h"

/**
 *
 *
 *
 *
 */

int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		line = input_line();
		args = tokenize(line, " ");

		if (!args || !args[0])
		{
			free_iteratively(args);
			free(line);
			continue;
		}

		pre_exec(args);
		free_iteratively(args);
		free(line);
	}

	return (0);
}
