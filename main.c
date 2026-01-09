#include "shell.h"

/** 
 * main - Entry point for the shell program
 * 
 * Return: 0 on success
 */

int main(void)
{
    if (isatty(STDIN_FILENO))
        shell_interactive();

    else
        shell_non_interactive();

    return (0);
}
