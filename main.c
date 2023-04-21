#include "simple_shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Description: Runs a simple shell program that reads commands from
 *              standard input, parses them, and executes them.
 *
 * Return:     Always returns EXIT_SUCCESS.
 */
int main(void)
{
	char *command_line = NULL;
	size_t len = 0;

	do {
		prompt();
		if (getline(&command_line, &len, stdin) == -1)
			break;

		/* code qui va exécuter la commande saisie */

	} while (1);

	free(command_line);
	return (EXIT_SUCCESS);
}
