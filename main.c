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
	char *cmd = NULL;
	int nb_cmd = 0;
	char **env = environ;
	char *full_path_cmd;
	size_t len = 0;
	ssize_t nb_char_read;
	int status;
	pid_t pid;
	char **args;
	char *cmd_name;
	char *path;
	char **path_list;
	int code = 0;

	/* Determine if the program is running in interactive mode or not */
	int interactive = isatty(STDIN_FILENO);

	path = _getenv("PATH", &(*env));
	path_list = tokenize_str_to_array(path, ":");
	if (path_list == NULL)
	{
		free_array(path_list);
		exit(128);
	}

	while (1)
	{
		/* If the program is running in interactive mode, print the prompt */
		if (interactive)
			printf("#cisfun$ ");

		nb_char_read = getline(&cmd, &len, stdin);
		nb_cmd++;

		/*remove the new line character at the end of the line*/
		if (nb_char_read > 0)
			cmd[nb_char_read - 1] = '\0';

		delete_spaces_begining(cmd);


		if (nb_char_read == -1)
		{
			/* STOP if "Ctrl+D" detected */
			if (interactive)
				printf("\n");

			free(cmd);
			free_array(path_list);
			exit(code);
		} else if (_strncmp(cmd, "exit", 4) == 0)
		{
			/* exit requested */
			free(cmd);
			free_array(path_list);
			exit(code);
		}
		if (_strlen(cmd) > 0)
		{
			/*a command has been typed*/
			code = 0;
			args = tokenize_str_to_array(cmd, " ");
			cmd_name = args[0];
			full_path_cmd = find_program_in_path(cmd_name, path_list);
			if (full_path_cmd == NULL)
			{
				free(cmd);
				free_array(args);
				free_array(path_list);
				free(full_path_cmd);
				exit(128);
			}

			if (_strncmp(full_path_cmd, "NOTFOUND", 8) == 0)
			{
				fprintf(stderr, "./hsh: %d: %s: not found\n", nb_cmd, cmd_name);
				code = 127;
			} else
			{
				pid = fork();
				if (pid == -1)
				{
					perror("fork");
					free(cmd);
					free_array(args);
					free_array(path_list);
					free(full_path_cmd);
					exit(129);
				} else if (pid == 0)
				{
					/*Child process*/
					execve(full_path_cmd, args, &(*env));
					free(cmd);
					free_array(args);
					free_array(path_list);
					free(full_path_cmd);
					perror("execve");
					exit(130);
				} else
				{
					/*Parent process*/
					wait(&status);
				}
			}
			if (_strncmp(full_path_cmd, "NOTFOUND", 8) == 0)
				free_array(args);
			else
			{
				free_array(args);
				free(full_path_cmd);
			}
		}
	}

	return (EXIT_SUCCESS);
}
