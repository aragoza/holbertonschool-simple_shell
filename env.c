#include "shell.h"

/**
 * _getenv - Get env value by name
 * @name: Name of ENV value
 *
 * Return: ENV Value
 */
char *_getenv(const char *name) /* _getenv("LOGNAME") -> Ilan */
{ /* In ENV all value is stored like this:   LOGNAME=Ilan   */
	int i = 0;
	char *strToken;
	char *result = NULL;

	while (environ[i] != NULL)
	{
		strToken = strtok(environ[i], "="); /* Get string before = */
		if (strToken == NULL)
			continue; /* If fail to get string before = then skip this ENV value */

		if (strcmp(strToken, name) == 0) /* Check if string before is name */
		{
			/* If name is desired name then set result to string after = */
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
list_t *get_path(  )
{
	char *strToken;
	char *path, *_path;
	list_t *new, *head = NULL;

	path = _getenv("PATH"); /* Get PATH Value in ENVIRONEMENT */
	if (path == NULL)
		return (NULL);

	_path = strdup(path); /* Make a copy of path has _path */
	if (_path == NULL)
		return (NULL); /* If copy fail, return NULL */

	strToken = strtok(_path, ":"); /* Get _path element before : */
	while (strToken != NULL)
	{
		new = malloc(sizeof(list_t)); /* Alloc new list_t */
		if (new == NULL)
		{
			free(_path); /* Free _path in memory */
			free_list(head); /* Free all path list in memory */
			return (NULL);
		}

		new->str = strdup(strToken); /* Make a copy of element of _path before : */
		if (new->str == NULL)
		{
			free(new); /* Free new list element in memory */
			free(_path); /* Free the copy of the path */
			free_list(head); /* Free all the list in memory */
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
