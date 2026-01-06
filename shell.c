#include "shell.h"

int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		line = input_line();
		args = tokenize(line, "\t\n");


	}

	return (0);
}
