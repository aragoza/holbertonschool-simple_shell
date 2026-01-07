#include "shell.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - Count length of an string
 * @str: String
 *
 * Return: Length
 */
int _strlen(char *str)
{
	int len = 0;

	while (*(str + len) != '\0')
		len++;

	return (len);
}

/**
 * str_concat - Concatenate two string
 * @s1: First string
 * @s2: Last string
 *
 * Return: Pointer of concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	int i, y, len1, len2;

	len1 = 0;
	len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (y = 0; y < len2; y++)
		result[i + y] = s2[y];

	result[i + y] = '\0';

	return (result);
}
