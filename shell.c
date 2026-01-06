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
		args = tokenize(line, "\t\n");

		if (!args || !args[0])
		{
			free(args);
			free(line);
			continue;
		}

		pre_exec(args);
		free(args);
		free(line);
	}

	return (0);
}
