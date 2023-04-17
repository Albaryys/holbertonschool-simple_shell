#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");
	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	printf("%s", line);

	free(line);
	exit(EXIT_SUCCESS);
}
