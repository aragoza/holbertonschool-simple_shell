#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

extern char **environ;

/**
 * struct builtin_s - function builtin
 * @name: name of the command
 * @func: function pointer
 *
 * Description: struct for array of builtin function
 */

typedef struct builtin_s
{
	char *name;
	int (*func)(char **args);
} builtin_t;

char *_getenv(const char *name);

char *input_line(void);
char **tokenize(char *line, char *delim);
char *find_command_in_path(char *cmd);
char *find_command_in_bin(char *cmd);
int check_and_execute_builtin(char **args);
int execute_command(char **args);

/* string.c */
int _strlen(char *str);
char *str_concat(char *s1, char *s2);

/* env.c */
char *_getenv(const char *name);
char *get_path(char *name);

/* free.c */
/** void free_list(list_t *head);*/
void free_iteratively(char **argv);


#endif /* SHELL_H */
