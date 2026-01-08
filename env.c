#include "shell.h"

/**
 * _getenv - Get env value by name
 * @name: Name of ENV value
 *
 * Return: ENV Value
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *strToken;
	char *result = NULL;

	while (environ[i] != NULL)
	{
		strToken = strtok(environ[i], "=");
		if (strToken == NULL)
			continue;

		if (strcmp(strToken, name) == 0)
		{
			result = strtok(NULL, "=");
			break;
		}

		i++;
	}

	return ((char *)result);
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
