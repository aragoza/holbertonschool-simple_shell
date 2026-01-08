#include "shell.h"

/**
 * _getenv - Get env value by name
 * @name: Name of ENV value
 *
 * Return: ENV Value
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len;
	char *value;

	if (!name)
		return (NULL);

	len = strlen(name);

	env = environ;
	while (*env != NULL)
	{
		/* Check if the environment string starts with name + '=' */
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			value = *env + len + 1; /* Skip over 'NAME=' */
			return (value);
		}
		env++;
	}

	return (NULL); /* Not found */
}

/**
 * get_path - Find the full path of a command using PATH
 * @cmd: The command name to find
 *
 * Return: Full path to the command, or NULL if not found
 */

char *get_path(char *cmd)
{
	char *path;
	char *path_dup;
	char *dir;
	char *full_path;
	int len;

	path = _getenv("PATH"); /* Use our custom getenv */
	if (!path)
		return (NULL);

	path_dup = strdup(path);
	if (!path_dup)
		return (NULL);

	dir = strtok(path_dup, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + 1 + strlen(cmd) + 1;
		full_path = (char *)malloc(len);
		if (!full_path)
		{
			free(path_dup);
			return (NULL);
		}
		/* Combine directory and command */
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_dup);
			return (full_path); /* caller must free */
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL); /* Not found */
}
