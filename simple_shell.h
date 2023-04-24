#ifndef _SIMPLESHELL_
#define _SIMPLESHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *prompt(void);
char *getinput(void);
char *_getenv(const char *name);
char *search_path(char *command, char **env);

#endif
