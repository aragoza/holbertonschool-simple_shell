#include "shell.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * execute_command - execute the command found in bin or path
 * @args: array of token
 *
 * Return: 0 on success -1 on failed
 */
char *get_bin_path(char **args)
{
	int path_len;
	list_t *head, *path;
	char *path_str, *new_bin_path;

	new_bin_path = str_concat("/bin/", args[0]);
	if (access(new_bin_path, X_OK) == 0)
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

			if (access(new_bin_path, X_OK) == 0)
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

int execute_command(char **args)
{
	char *cmd_path;
	pid_t pid;
	int status;

	if (!args || !args[0])
		return (-1);
	if (check_and_execute_builtin(args) == 0) /* 1. Check built-ins first */
		return (0); /* Successful executed*/

	cmd_path = get_bin_path(args); /* 2. Search in /bin and all dirs of PATH */

	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (-1);
	}
	/* 4. Fork and execute external command */
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		free(cmd_path);
		return (-1);
	}
	if (pid == 0) /* child process */
	{
		execve(cmd_path, args, environ);
		perror("execve failed");
		exit(1);
	}
	else /* parent process */
		wait(&status);

	free(cmd_path);
	return (status);
}
