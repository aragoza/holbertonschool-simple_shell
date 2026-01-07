#include "total.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void execute_args(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path;

    if (!args || !args[0])
        return;

    /** resolve the command path once */
    cmd_path = pre_exec(args[0]);

    if (!cmd_path)
    {
        /** avoid loop and stop here if not found */
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    pid = fork();

    if (pid == 0)
    {
        /** child process */
        execve(cmd_path, args, environ);
        perror("execve"); /** only reached if execve fails */
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    free(cmd_path); /** free the resolved path */
}
