#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 *
 *
 *
 *
 *
 *
 */


char **tokenize(char *line, char *delim)
{
    char **argv;
    char *token;
    int i = 0, count = 0;
    char *tmp;

    if (!line || !delim)
        return (NULL);


    tmp = strdup(line);
    if (!tmp)
        return (NULL);

    token = strtok(tmp, delim);
    while (token)
    {
        count++;
        token = strtok(NULL, delim);
    }
    free(tmp);

    argv = malloc(sizeof(char *) * (count + 1));
    if (!argv)
        return (NULL);

    token = strtok(line, delim);
    while (token)
    {
        argv[i++] = strdup(token);
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    return (argv);
}
