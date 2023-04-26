#ifndef _SIMPLESHELL_
#define _SIMPLESHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_getenv(const char *name, char **env);
size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *find_program_in_path(char *program_name, char **path_list);
char **tokenize_str_to_array(char *cmd, char *delimiter);
void free_array(char **arr);

#endif
