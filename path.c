#include "shell.h"

/**
 * pathFind - finds the string in **env that contains the path
 * @env: Double pointer array to user env
 *
 * Return: PATH string
 */
char *pathFind(char **env)
{
	char *path = "PATH";
	int index;
	for (index = 0; env[index] != NULL; index++)
	{
		if (strncmp(env[index], path, 4) == 0)
			return(env[index]);
	}
	return (NULL);
}
/**
 * execPath - Makes an executable path
 * @PATH: Full path from evn
 * @cmd: The command from the command line
 *
 * Return: Pointer to full executable path
 */
char *execPath(char *PATH, char *cmd)
{
	char **path;
	char *buffer;
	char *bufPointer, *cmdPointer;
	char *command;
	int index;
	struct stat fileStat;

	path = vect(PATH, strlen(PATH) + 1);
	command = malloc(sizeof(cmd + 1));
	strcpy(command, cmd);

	for (index = 1; path[index] != NULL; index++)
	{
		cmdPointer = command;
		buffer = malloc(strlen(path[index]) + strlen(cmd) + 2);
		if (buffer == NULL)
			return (NULL);
		for (;*cmdPointer != '\0'; cmdPointer++)
		{
			if (*cmdPointer == '/')
			{
				free(buffer);
				freeArray(path);
				return(command);
				break;
			}
		}
		strncpy(buffer, path[index], strlen(path[index]) + 1);
		bufPointer = buffer;
		cmdPointer = command;
		while (*bufPointer != '\0')
			bufPointer++;
		if (*bufPointer == '\0')
		{
			*bufPointer = '/';
			bufPointer++;
		}
		while (*cmdPointer != '\0')
		{
			*bufPointer = *cmdPointer;
			cmdPointer++;
			bufPointer++;
		}
		*bufPointer = '\0';
		if (stat(buffer, &fileStat) == 0)
		{
			free(command);
			freeArray(path);
			return (buffer);
			break;
		}
	}
	free(buffer);
	return (NULL);
}
