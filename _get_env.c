#include "shell.h"
#include <string.h>

/**
 * _get_env - will return the value of the environ
 * @name: the environ variable
 *
 * Return: the value of environ
 */

char *_getenv(const char *name)
{
	char **env;
	size_t len;
	char *value;

	if (!name)
		return NULL;

	len = strlen(name);

	env = environ;
	while (*env != NULL)
	{
		/* Check if the environment string starts with name + '=' */
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			value = *env + len + 1; /* Skip over 'NAME=' */
			return value;
		}
		env++;
	}

	return NULL; /* Not found */
}
