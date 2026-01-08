#include "shell.h"

/**
 * free_iteratively - free iteratively an array of pointer
 * @argv: the array of token
 *
 * no return : void output
 */
void free_iteratively(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}

	free(argv);
}

/**
 * free_list - Free a list
 * @head: List
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}
