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
