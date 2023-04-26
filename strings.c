#include "simple_shell.h"

/**
 * _strlen - This function returns the length of a string
 *
 * @s: pointer of integer s
 *
 * Return: length of a string
 */

size_t _strlen(const char *s)
{
	size_t length = 0;

	while (*s++)
		length++;

	return (length);
}


/**
 * _strdup - Duplicate a string.
 * @str: Pointer to the string to be duplicated.
 *
 * Return: Pointer to the newly allocated duplicate string,
 *         or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup_str;
	size_t len, i;

	if (!str)
		return (NULL);

	len = _strlen(str);

	dup_str = malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);

	/* Copy the string to the new buffer */
	for (i = 0; i < len; i++)
		dup_str[i] = str[i];

	dup_str[len] = '\0';

	return (dup_str);
}

/**
 * _strncmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: the size to compare
 *
 * Return: 0 if s1 and s2 are equal, a negative value if s1 is less than s2,
 *         or a positive value if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((int) (s1[i] - s2[i]));
		} else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
  * _strcat - Concatenates two strings
  * @dest: The destination string
  * @src: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_strcat(char *dest, char *src)
{
	int dlen = 0, i;

	while (dest[dlen])
	{
		dlen++;
	}

	for (i = 0; src[i] != 0; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}

	dest[dlen] = '\0';
	return (dest);
}
/**
 * _strcpy - Copy a string source to string destination
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the string destination
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}
