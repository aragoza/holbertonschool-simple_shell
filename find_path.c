#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_command - Find the full path of a command using PATH
 * @cmd: The command name to find
 *
 * Return: Full path to the command, or NULL if not found
 */

char *find_command_in_path(char *cmd)
{
    char *path;
    char *path_dup;
    char *dir;
    char *full_path;
    int len;

    path = _getenv("PATH"); /* Use our custom getenv */
    if (!path)
        return NULL;

    path_dup = strdup(path);
    if (!path_dup)
        return NULL;

    dir = strtok(path_dup, ":");
    while (dir != NULL)
    {
        /* Allocate memory for dir/cmd and null terminator */
        len = strlen(dir) + 1 + strlen(cmd) + 1;
        full_path = (char *)malloc(len);
        if (!full_path)
        {
            free(path_dup);
            return NULL;
        }
        /* Combine directory and command */
        sprintf(full_path, "%s/%s", dir, cmd);
        /* Check if the executable exists */
        if (access(full_path, X_OK) == 0)
        {
            free(path_dup);
            return full_path; /* caller must free */
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_dup);
    return NULL; /* Not found */
}
