#include "shell.h"

/**
 * exit - exits the shell
 * @buffer: buffer to clean up
 *
 * Return: void
 */
void exitShell(char *buffer)
{
	char *ex = "exit";

	if (_strcmp(buffer, ex) == 0)
	{
		free(buffer);
		exit(2);
	}
}
