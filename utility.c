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

/**
 * getinput - read input from user
 *
 * Return: a pointer to a string containing the user's input
 */
char *getinput(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		perror("getline");
		free(input);
		input = NULL;
	}

	return (input);
}
