#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_command(char **args)
{
    char *cmd_path;
    pid_t pid;
    int status;

    if (!args || !args[0])
        return -1;

    /* 1. Check built-ins first */
    if (check_and_execute_builtin(args) == 0)
        return 0; /* built-in executed successfully */

    /* 2. Search PATH */
    cmd_path = find_command_in_path(args[0]);

    /* 3. If not found, try /bin */
    if (cmd_path == NULL)
        cmd_path = find_command_in_bin(args[0]);

    if (cmd_path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return -1;
    }

    /* 4. Fork and execute external command */
    pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        free(cmd_path);
        return -1;
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
    return status;
}
