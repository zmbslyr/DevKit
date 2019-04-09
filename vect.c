#include "shell.h"

/**
 * vect - Takes a string and puts it into a vector array
 * @str: String to break apart
 * @n: Size to malloc
 *
 * Return: Pointer to an array of pointers
 */
char **vect(char *str, ssize_t n)
{
	char *buffer, *bufPointer, *token, *delim = " ";
	char **args;
	size_t tokenSize = 1;
	int argc;

	buffer = malloc(n + 1);
	if (buffer == NULL)
		return (NULL);
	bufPointer = buffer;
	strcpy(buffer, str);
	for (argc = 0; *bufPointer != '\0'; bufPointer++)
	{
		if (*bufPointer == *delim)
			tokenSize++;
	}
	args = malloc(sizeof(char *) * (tokenSize + 1));
	token = strtok(buffer, delim);
	argc = 0;
	while (token != NULL)
	{
		args[argc] = malloc(strlen(token) + 1);
		strcpy(args[argc], token);
		token = strtok(NULL, delim);
		argc++;
	}
	args[argc] = NULL;
	free(buffer);
	return (args);
}
