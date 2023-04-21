#include <simple_shell.h>

/**
 * _strlen - returns the length of a string
 * @s: a string to measure
 * Return: 0 if fails
 */
int _strlen(char *s)
{
	int c;

	c = 0;
	if (*s != '\0')
	{
		c = 1 + _strlen(s + 1);
		return (c);
	}
	else
	{
		return (0);
	}
}

/**
 * _strdup - Duplicate a string.
 * @str: Pointer to the string to be duplicated.
 *
 * Return: Pointer to the newly allocated duplicate string,
 *         or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	char *dup_str;
	size_t len;

	if (!str)
		return (NULL);

	len = _strlen(str);

	dup_str = malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);

	/* Copy the string to the new buffer */
	for (size_t i = 0; i < len; i++)
		dup_str[i] = str[i];

	dup_str[len] = '\0';

	return (dup_str);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if s1 and s2 are equal, a negative value if s1 is less than s2,
 *         or a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

