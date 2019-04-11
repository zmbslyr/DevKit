#include "shell.h"

/**
 * cd - change user directory
 * @path: path to change to
 *
 * Return: void
 */
void cd(char *cmd, char *path)
{
	char *cd = "cd";
	int fd;

	if (cmd == NULL || strcmp(cmd, cd) == 0)
	{
		if (cmd == NULL)
			return;
		if (path == NULL && cmd != NULL)
		{
			fd = chdir(getenv("HOME"));
		}
		else if (cmd != NULL)
		{
			fd = chdir(path);
			if (fd < 0)
				perror(cmd);
		}
	}
}
