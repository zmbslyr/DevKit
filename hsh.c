#include "shell.h"

/**
 * main - Simple Shell
 * @argc: number of arguments
 * @argv: Arguments stored as string
 * @envp: Enviroment parameters
 *
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer = NULL, *path, *pathExec;
	size_t bufSize = 0;
	pid_t newProcess;
	ssize_t charCount;
	int status, count;
	char **array;

	if (argc < 1)
		return (-1);
	while (1)
	{
		write(STDERR_FILENO, "($) ", 4);
		charCount = getline(&buffer, &bufSize, stdin);
		if (charCount < 0)
			break;
		if (buffer[charCount - 1] == '\n')
			buffer[charCount - 1] = '\0';
		array = vect(buffer, charCount);
		path = pathFind(envp);
		pathExec = execPath(path, array[0]);

		newProcess = fork();
		if (newProcess < 0)
			perror(argv[0]);
		if (newProcess == 0)
		{
			execve(pathExec, array, envp);
			perror(argv[0]);
			exit(2);
		}
		else
			wait(&status);
		freeArray(array);
		free(pathExec);
		count++;
	}
	if (charCount < 0)
		write(STDERR_FILENO, "\n", 1);
	free(buffer);
	return (0);
}
