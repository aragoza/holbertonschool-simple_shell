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
 * get_path - Get all dirs in the PATH
 *
 * Return: Singly linked with dirs
 */
list_t *get_path()
{
	char *strToken;
	char *path, *_path;
	list_t *new, *head = NULL;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	_path = strdup(path);
	if (_path == NULL)
		return (NULL);

	strToken = strtok(_path, ":");
	while (strToken != NULL)
	{
		new = malloc(sizeof(list_t));
		if (new == NULL)
		{
			free(_path);
			free_list(head);
			return (NULL);
		}

		new->str = strdup(strToken);
		if (new->str == NULL)
		{
			free(new);
			free(_path);
			free_list(head);
			return (NULL);
		}

		new->len = _strlen(strToken);
		new->next = head;
		head = new;
		strToken = strtok(NULL, ":");
	}

	free(_path);
	return (head);
}
