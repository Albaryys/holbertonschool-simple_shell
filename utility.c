#include "simple_shell.h"

/**
 * _getenv - Function that gets the value of the environmental variable.
 * @name_var_env: Name of the environmental variable.
 * @env: The environement.
 *
 * Return: The value of the environmental variable or NULL if the variable is
 * not found.
 */
char *_getenv(const char *name_var_env, char **env)
{
	size_t len_name_var_env = _strlen(name_var_env);

	while (*env != NULL)
	{
		if (_strncmp(name_var_env, *env, len_name_var_env)
				== 0 && (*env)[len_name_var_env] == '=')
		{
			return (&(*env)[len_name_var_env + 1]);
		}
		env++;
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
 * find_program_in_path - searches for the full path of a given program name
 * @program_name: the name of the program.
 * @path_list: the list of each path folders.
 *
 * Return: the full path of the program found, otherwise "NOTFOUND"
 */
char *find_program_in_path(char *program_name, char **path_list)
{
	char *full_path;

	while (*path_list != NULL)
	{
		/* Construct the full path to the program */
		full_path = malloc(sizeof(*full_path) * (_strlen(*path_list)
					+ _strlen(program_name) + 2));
		if (full_path == NULL)
			return (NULL);

		sprintf(full_path, "%s/%s", *path_list, program_name);
		/* Check if the program exists in this directory */
		if (access(full_path, F_OK) != -1)
		{
			return (full_path);   /* program found */
		}
		path_list++;    /* move to the next directory */
		free(full_path);
	}
	return ("NOTFOUND");   /* program not found */
}

/**
 * free_array - Free an array
 * @arr: the name of the array to be freeing.
 */
void free_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


/**
 * tokenize_str_to_array - Tokenize a string into an array.
 * @cmd: The string
 * @delimiter: The delimiter
 *
 * Return: the pointer to the array
 */
char **tokenize_str_to_array(char *cmd, char *delimiter)
{
	char *cmd_copy = _strdup(cmd);
	char **args = NULL;
	int num_tokens = 0;
	int i = 0;
	char *token = strtok(cmd, delimiter);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delimiter);
	}

	args = malloc(sizeof(*args) * (num_tokens + 1));
	if (args == NULL)
	{
		free(cmd);
		free(cmd_copy);
		exit(EXIT_FAILURE);
	}
	/* allouer la mémoire pour le tableau de pointeurs */
	token = strtok(cmd_copy, delimiter);

	while (token != NULL)
	{
		/* allouer la mémoire pour stocker la chaîne de caractères et la copier */
		args[i] = _strdup(token);
		i++;
		token = strtok(NULL, delimiter);
	}

	args[num_tokens] = NULL; /* dernière case du tableau égale à NULL */
	free(cmd_copy);
	return (args);
}
