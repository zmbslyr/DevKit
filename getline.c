#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **vect(char *str, ssize_t n);

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments in string format
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	char **array;
	size_t bufSize = 0;
	ssize_t charCount;
	int index;

	if (argc == 0)
		return (-1);
	if (argv == NULL)
		return (-1);

	putchar('$');
	putchar(' ');
	charCount = getline(&buffer, &bufSize, stdin);
	if (charCount < 0)
		return (-1);
	array = vect(buffer, charCount);
	printf("%s\n%s\n%s\n", array[0], array[1], array[2]);
     	free(buffer);
	for (index = 0; array[index] != NULL; index++)
		free(array[index]);
	free(array);
	return (0);
}


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
