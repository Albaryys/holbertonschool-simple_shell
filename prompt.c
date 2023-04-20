#include "simple_shell.h"

/**
 * prompt - Displays a prompt for the user to enter a command
 *
 * Return: A pointer to a string containing the user's command
 */
char	*prompt(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		getline(&buffer, &bufsize, stdin);
		printf("%s", buffer);
		return (buffer);
	}
}
