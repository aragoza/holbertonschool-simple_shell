#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

/* string.c */
char *str_concat(char *s1, char *s2);

int pre_exec(char **args);

#endif
