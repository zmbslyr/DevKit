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
	ssize_t charCount;
	char **array;

	if (argc < 1 || argv == NULL)
		return (-1);
	globals.count = 1;
	if (isatty(STDOUT_FILENO) == 1 && isatty(STDIN_FILENO) == 1)
		flags.interactive = 1;
	while (1)
	{
		if (flags.interactive)
			write(STDERR_FILENO, "($) ", 4);
		charCount = getline(&buffer, &bufSize, stdin);
		if (charCount < 0)
			break;
		if (buffer[charCount - 1] == '\n')
			buffer[charCount - 1] = '\0';
		exitShell(buffer);
		array = vect(buffer, charCount);
		path = pathFind(envp);
		pathExec = execPath(path, array[0]);
		cd(array[0], array[1]);
		if (builtins(array[0]))
		{
			if (pathExec != NULL)
				newProcess(pathExec, array, envp);
			freeArray(array);
		}
		else
			freeArray(array);
		free(pathExec);
		globals.count++;
	}
	if (charCount < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(buffer);
	return (0);
}

/**
 * newProcess - Creates a new process
 * @pathExec: Executable path
 * @args: Array of arguments given
 * @env: Array of env variables
 *
 * Return: void
 */
void newProcess(char *pathExec, char **args, char **env)
{
	pid_t newProcess;
	int status;

	newProcess = fork();
	if (newProcess < 0)
		perror(args[0]);
	if (newProcess == 0)
	{
		execve(pathExec, args, env);
		perror(args[0]);
		exit(2);
	}
	else
		wait(&status);
}
/**
 * builtins - checks if cmd is a built-in
 * @cmd: Command to check
 *
 * Return: 0 if built-in, 1 if not
 */
int builtins(char *cmd)
{
	char *built[2] = {
		"cd",
		NULL
	};
	int index;

	for (index = 0; built[index] != NULL; index++)
	{
		if (cmd == NULL || strcmp(cmd, built[index]) == 0)
			return (0);
	}
	return (1);
}
