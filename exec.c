#include "shell.h"

#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * get_bin_path - Get binary path with his name
 * @args: Arguments (Array of command line splited by space)
 *
 * Return: Path of binary
 */
char *get_bin_path(char **args)
{
	int path_len;
	list_t *head, *path;
	char *path_str, *new_bin_path;

	if (access(args[0], X_OK) == 0) /* If command is a bin*/
		return (args[0]); /* Return the bin given by user*/
	new_bin_path = str_concat("/bin/", args[0]);/* Concat /bin + command*/
	if (access(new_bin_path, X_OK) == 0)/* Check if /bin + command is executable */
		return (new_bin_path);
	free(new_bin_path);

	head = path = get_path(); /* Set path to get_path and copy it to head */
	while (path != NULL)
	{
		if (path->str != NULL)
		{
			path_str = path->str; /* Get the dir path */
			path_len = _strlen(path_str); /* Get length of the dir path */

			if (path_str[path_len - 1] != '/') /* If path don't finish by / */
				path_str = str_concat(path_str, "/"); /* Then add / at end of path_str */
			new_bin_path = str_concat(path_str, args[0]);/*Concat dir path and command*/
			free(path_str);

			/* Check if the command is an executable in the dir of the path */
			if (access(new_bin_path, X_OK) == 0)
				break; /* Stop search in path bc its found */
			free(new_bin_path); /* Free new_bin_path of memory */
		}
		path = path->next; /* Set path to the next path*/
	}

	free_list(head); /* Free the path list*/
	if (new_bin_path != NULL)
		return (new_bin_path); /* If path found then return path*/
	return (NULL); /* If not found then return NULL*/
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

	pid = fork(); /* 4. Fork and execute external command */
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
