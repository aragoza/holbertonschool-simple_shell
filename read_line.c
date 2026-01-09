#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * input_line - read the stream and stock in buffer
 *
 * Return: buffer on success or NULL on fail
 */

char *input_line(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	size_t len;

	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		free(buffer);
		return (NULL); /* EOF or error */
	}

	/* Remove trailing newline */
	if (buffer[0] != '\0')
	{
		len = strlen(buffer);

		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
	}

	return (buffer);
}

/**
 * _strchr - locate character in string
 * @s: string to search
 * @c: character to locate
 *
 * Return: pointer to the character
 */

char *_strchr(const char *s, int c)
{
    int i = 0;

    if (!s)  /* Handle NULL pointer */
        return NULL;

    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (char *)(s + i);  /* Return pointer to the match */
        i++;
    }

    /* Check if c is the null terminator '\0' */
    if (c == '\0')
        return (char *)(s + i);

    return NULL;  /* Not found */
}