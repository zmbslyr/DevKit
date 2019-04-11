#include "shell.h"

/**
 * pathFind - finds the string in **env that contains the path
 * @env: Double pointer array to user env
 *
 * Return: PATH string
 */
char *pathFind(char **env)
{
	char *path = "PATH=";
	int index;

	for (index = 0; env[index] != NULL; index++)
	{
		if (strncmp(env[index], path, 5) == 0)
			return (env[index]);
	}
	return (NULL);
}

char *execPath(char *PATH, char *cmd)
{
	char **path;
	char *cmdPointer, *buffer, *command;
	int index;
	struct stat fileStat;

	if (builtins(cmd))
	{
		path = vect(PATH, strlen(PATH) + 1);
		command = malloc(sizeof(char) * strlen(cmd) + 1);
		strcpy(command, cmd);

		for (index = 1; path[index] != NULL; index++)
		{
			cmdPointer = command;
			buffer = malloc(strlen(path[index]) + strlen(cmd) + 2);
			if (buffer == NULL)
				return (NULL);
			for (; *cmdPointer != '\0'; cmdPointer++)
			{
				if (*cmdPointer == '/')
				{
					free(buffer);
					freeArray(path);
					return (command);
				}
			}
			strncpy(buffer, path[index], strlen(path[index]) + 1);
			apndCmd(buffer, command);
			if (stat(buffer, &fileStat) == 0)
			{
				free(command);
				freeArray(path);
				return (buffer);
			}
			else
				free(buffer);
		}
		freeArray(path);
		if (buffer)
		{
			printf("hsh: %i: %s: not found\n", globals.count, command);
			free(command);
			return (NULL);
		}
	}
	return (NULL);
}


void apndCmd(char *buffer, char *cmd)
{
	char *bufPointer, *cmdPointer;

	bufPointer = buffer;
	cmdPointer = cmd;
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
}
