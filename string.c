#include "shell.h"

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

/**
 * _strdup - Duplicate string
 * @str: String to duplicate
 *
 * Return: Pointer of string
 */
char *_strdup(char *str)
{
	unsigned int i, len = 0;
	char *result = NULL;

	if (str == NULL)
		return (NULL);

	while (*(str + len) != '\0')
		len++;

	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		result[i] = *(str + i);

	return (result);
}

/**
 * _strcmp - Compare two string
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if strings is eqal
 */
int _strcmp(const char *s1, const char *s2)
{
	unsigned int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
