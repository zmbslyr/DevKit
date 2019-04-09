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
	char *buffer = NULL;
	size_t bufSize = 0;
	pid_t newProcess;
	ssize_t charCount;
	int status, index;
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
		newProcess = fork();
		if (newProcess < 0)
			perror(argv[0]);
		if (newProcess == 0)
		{
			execve(array[0], array, envp);
			perror(argv[0]);
			exit(2);
		}
		else
			wait(&status);
		for (index = 0; array[index] != NULL; index++)
			free(array[index]);
		free(array);
	}
	if (charCount < 0)
		write(STDERR_FILENO, "\n", 1);
	free(buffer);
	return (0);
}
