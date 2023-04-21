#include "simple_shell.h"

/**
 * _getenv - Function that gets the value of the environmental variable.
 * @name: Name of the environmental variable.
 *
 * Return: The value of the environmental variable or NULL if the variable is
 * not found.
 */
char *_getenv(const char *name)
{
	int i;
	char **env;
	char *path;

	for (i = 0; environ[i]; i++)
	{
		if (_strcmp(environ[i], name) == 0)
		{
			path = environ[i] + _strlen(name) + 1;
			return (path);
		}
	}
	return (NULL);
}
