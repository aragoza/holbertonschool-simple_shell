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
	list_t *head, *path;
	char *path_str, *new_bin_path, *dir;
	int path_len;

	if (!args || !args[0])
		return (NULL);

	/* 1. If command contains '/' and is executable, return it directly */
	if (_strchr(args[0], '/') && access(args[0], X_OK) == 0)
		return args[0]; /* Caller must NOT free this */

	/* 2. Try /bin/command */
	new_bin_path = str_concat("/bin/", args[0]);
	if (access(new_bin_path, X_OK) == 0)
		return new_bin_path;
	free(new_bin_path);

	/* 3. Search directories from PATH */
	head = path = get_path();
	while (path != NULL)
	{
		if (path->str != NULL)
		{
			path_str = path->str;
			path_len = _strlen(path_str);

			/* Ensure directory path ends with '/' */
			if (path_str[path_len - 1] != '/')
				dir = str_concat(path_str, "/");
			else
				dir = path_str;

			/* Concatenate directory + command */
			new_bin_path = str_concat(dir, args[0]);
			if (new_bin_path != NULL && access(new_bin_path, X_OK) == 0)
			{
				if (path_str[path_len - 1] != '/')
					free(dir);
				free_list(head); /* Free linked list of PATH */
				return (new_bin_path);
			}

			/* Free temporary strings if needed */
			if (new_bin_path != NULL)
				free(new_bin_path);
			if (path_str[path_len - 1] != '/')
				free(dir);
		}
		path = path->next;
	}

	free_list(head);
	return (NULL); /* Command not found in PATH */
}

/**
 * execute_command - executes a command
 * @args: array of token
 *
 * Return: 0 on success
 */
int execute_command(char **args)
{
	char *cmd_path;
	pid_t pid;
	int status; 

	if (!args || !args[0])
		return (-1);
	if (check_and_execute_builtin(args) == 0) 	/* 1. Built-ins */
		return (0);
	if (execute_args(args) == 0)		/* 2. Direct command */
		return (0);
	cmd_path = get_bin_path(args);	/* 3. Search PATH */
	if (!cmd_path)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (-1);
	}
	pid = fork();	/* 4. Fork and exec PATH command */
	if (pid < 0)
	{
		perror("fork failed");
		free(cmd_path);
		return (-1);
	}
	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror(cmd_path);
		free(cmd_path);
		exit(EXIT_FAILURE);
	}

	wait(&status);
	free(cmd_path);
	return (status);
}

/**
 * execute_args - executes a command directly if it's an absolute path
 * @args: array of token
 *
 * Return: 0 on success
 */

int execute_args(char **args)
{
	pid_t pid;
	int status;

	if (strchr(args[0], '/')) 	/* 2. Direct execution if path contains '/' */
	{
		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, environ);
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(&status);
			return (status);
		}
		else
		{
			perror("fork failed");
			return (-1);
		}
	}
	return (-1);
}