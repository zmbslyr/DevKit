#ifndef _SHELL_
#define _SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
char **vect(char *str, ssize_t n);
char *argToString(char **args);
void freeArray(char **arr);
char *pathFind(char **env);
char *execPath(char *PATH, char *cmd);
#endif /* _SHELL_ */
