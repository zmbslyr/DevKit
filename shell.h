#ifndef _SHELL_
#define _SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

/* Base Functions */
char **vect(char *str, ssize_t n);
char *argToString(char **args);
void freeArray(char **arr);
char *pathFind(char **env);
char *execPath(char *PATH, char *cmd);
void newProcess(char *pathExec, char **args, char **env);
void apndCmd(char *buffer, char *cmd);

/* Built-ins */
int builtins(char *cmd);
void cd(char *cmd, char *path);
void exitShell(char *buffer);


/* GLOBALS */
/**
 * global - stuff
 * @count: global line count
 *
 * Definition: something
 */
struct global
{
	int count;
} globals;

/**
 * flag - flags for the system
 * @interactive: checks for interactive mode
 *
 * Definition: Flags for the system
 */
struct flag
{
	bool interactive;
} flags;

#endif /* _SHELL_ */
