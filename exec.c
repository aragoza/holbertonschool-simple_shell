#include "shell.h"

#include <fcntl.h>
#include <sys/stat.h>

/**
 * get_bin_path - Get binary path with his name
 * @args: Arguments (Array of command line splited by space)
 *
 * Return: Path of binary
 */
char *get_bin_path(char **args)
{
	struct stat sb;
	int fd, path_len;
	list_t *head, *path;
	char *path_str, *new_bin_path;

	new_bin_path = str_concat("/bin/", args[0]);
	if (stat(new_bin_path, &sb) != -1)
	{
		return (new_bin_path);
	}
	free(new_bin_path);

	path = get_path();
	head = path;
	while (path != NULL)
	{
		if (path->str != NULL)
		{
			path_str = path->str;
			path_len = _strlen(path_str);

			if (path_str[path_len - 1] != '/')
				path_str = str_concat(path_str, "/");
			new_bin_path = str_concat(path_str, args[0]);
			free(path_str);

			if (stat(new_bin_path, &sb) != -1)
			{
				break;
			}
			free(new_bin_path);
		}
		path = path->next;
	}

	free_list(head);
	if (new_bin_path != NULL)
		return (new_bin_path);

	return ("");
}
