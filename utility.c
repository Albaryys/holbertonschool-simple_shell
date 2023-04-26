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

/**
 * search_path - searches for the full path of a given command
 * @command: the command to search for
 * @env: the environment variables
 * Return: the full path of the command if found, otherwise NULL
 */
char *search_path(char *command, char **env)
{
	char *path, *token, *tmp;
	struct stat st;

	if (!command || !env)
		return (NULL);

	path = _getenv("PATH", env);

	token = strtok(path, ":");
	while (token)
	{
		tmp = _strcat(token, "/");
		tmp = _strcat(tmp, command);

		if (stat(tmp, &st) == 0)
		{
			free(path);
			return (tmp);
		}
		free(tmp);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

