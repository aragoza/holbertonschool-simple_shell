#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

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

/* read_line.c */
char *input_line(void);

/* tokenize.c */
char **tokenize(char *line, char *delim);

/* check_then_exec_builtin.c */
int check_and_execute_builtin(char **args);

/* exec.c */
char *get_bin_path(char **args);
int execute_command(char **args);

/* string.c */
int _strlen(char *str);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* env.c */
char *_getenv(const char *name);
list_t *get_path();

/* free.c */
void free_list(list_t *head);
void free_iteratively(char **argv);

#endif /* SHELL_H */
