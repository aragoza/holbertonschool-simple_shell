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

int execute_command(char **args)
{
	char *cmd_path;
	pid_t pid;
	int status;

	if (!args || !args[0])
		return (-1);
	if (check_and_execute_builtin(args) == 0)
		return (0); /* built-in executed successfully */
	cmd_path = get_path(args[0]);
	if (cmd_path == NULL)
		cmd_path = _getenv(args[0]);
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
	{
		wait(&status);
	}

	free(cmd_path);
	return (status);
}
