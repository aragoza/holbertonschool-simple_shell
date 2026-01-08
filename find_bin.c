#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_command_in_bin - Find command in /bin if not found in PATH
 * @cmd: The command name to find
 *
 * Return: Full path to the command, or NULL if not found
 */

char *find_command_in_bin(char *cmd)
{
    char *full_path;

    /* 1. Search in PATH using our existing find_command */
    full_path = find_command_in_path(cmd);
    if (full_path != NULL)
        return full_path;

    /* 2. If not found, try /bin/command */
    full_path = (char *)malloc(strlen("/bin/") + strlen(cmd) + 1);
    if (!full_path)
        return NULL;

    sprintf(full_path, "/bin/%s", cmd);

    if (access(full_path, X_OK) == 0)
        return full_path; /* executable exists */

    free(full_path);
    return NULL; /* Not found */
}
