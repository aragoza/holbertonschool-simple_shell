#include "shell.h"

extern char **environ;

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

list_t *get_path()
{
	list_t *new = NULL;
	list_t *head = NULL;
	char *strToken = NULL;
	char *path = _getenv("PATH");

	strToken = strtok(path, ":");
	while (strToken != NULL)
	{
		new = malloc(sizeof(list_t));
		if (new == NULL)
			return (NULL);

		new->str = strdup(strToken);
		new->len = strlen(strToken);
		new->next = head;
		head = new;

		strToken = strtok(NULL, ":");
	}

	return (head);
}
