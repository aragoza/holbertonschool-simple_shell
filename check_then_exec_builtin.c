#include "shell.h"
#include <string.h>

extern char **environ;

/**
 * our_exit - This is the build-in of exit
 *
 * Return: 0
 */

int our_exit(void)
{
	exit(0);
	return (0);
}

/**
 * __env - This is the build-in of env
 *
 * Return: 0
*/

int __env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

/**
 * check_and_execute_builtin - check and execute builtin if find
 * @args: array of token passed in the stream
 *
 * Return: 0 on success, 1 on fail
*/

int check_and_execute_builtin(char **args)
{
	int i;
	builtin_t builtins[] = {
		{"exit", our_exit},
		{"env", __env},
		{NULL, NULL}
	};

	if (!args || !args[0])
		return (1);


	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{

			builtins[i].func(args);
			return (0);
		}
	}

	return (1);
}
