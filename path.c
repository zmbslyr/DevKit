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

/**
 * execPath - Creates full executable path for execve
 * @PATH: Full path from main
 * @cmd: Command to be added to path
 *
 * Return: Executable path for execve
 */
char *execPath(char *PATH, char *cmd)
{
	char **path;
	char *buffer = NULL, *command, *cmdPointer;

	command = malloc(sizeof(char) * strlen(cmd) + 1);
	if (command == NULL)
		return (NULL);
	strcpy(command, cmd);
	cmdPointer = command;
        for (; *cmdPointer != '\0'; cmdPointer++)
	{
		if (*cmdPointer == '/')
		{
			return (command);
		}

	}
	if (builtins(cmd))
	{
		path = vect(PATH, strlen(PATH) + 1);
		buffer = createPath(path, buffer, command);
		if (!buffer)
		{
			printf("hsh: %i: %s: not found\n", globals.count, command);
			freeArray(path);
			free(buffer);
			free(command);
			return (NULL);
		}
		else
		{
			free(command);
			return (buffer);
		}
		free(command);
	}
	free(command);
	return (NULL);
}

/**
 * apndCmd - appends cmd to the path
 * @buffer: Buffer where the path string is
 * @cmd: Command to be appended to path
 *
 * Return: void
 */
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


/**
 * createPath - creates the exec path
 * @path: Array of all possible paths
 * @buffer: Buffer to change
 * @cmd: command
 *
 * Return: void
 */
char *createPath(char **path, char *buffer, char *cmd)
{
	int index;
	struct stat fileStat;

	for (index = 1; path[index] != NULL; index++)
	{
		buffer = malloc(strlen(path[index]) + strlen(cmd) + 2);
		if (buffer == NULL)
			return (NULL);
		strncpy(buffer, path[index], strlen(path[index]) + 1);
		apndCmd(buffer, cmd);
		if (stat(buffer, &fileStat) == 0)
		{
			freeArray(path);
			return (buffer);
		}
		free(buffer);
	}
	return (NULL);
}
