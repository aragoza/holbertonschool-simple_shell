#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

/* string.c */
char *str_concat(char *s1, char *s2);

/* env.c */
char *_getenv(const char *name);
list_t *get_path();

void free_iteratively(char **argv);

char *input_line(void);

char **tokenize(char *line, char *delim)

/* exec.c */
int pre_exec(char **args);

/** _executee_arg.c */
void execute_args(char **args);

#endif