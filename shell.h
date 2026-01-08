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

typedef struct builtin_s
{
    char *name;
    int (*func)(char **args);
} builtin_t;

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
list_t *get_path();

/* free.c */
void free_list(list_t *head);
void free_iteratively(char **argv);


#endif /* SHELL_H */