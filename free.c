#include "shell.h"

/**
 * free_iteratively - free iteratively an array of pointer
 * @argv: the array of token
 *
 * no return : void output
 */

void free_iteratively(char **argv)
{
	int i = 0;

	while (argv[i])
		free(argv[i++]);
	free(argv);
}
