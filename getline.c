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
	char *buffer;
	char **array;
	size_t bufSize = 0;
	ssize_t charCount;

	if (argc == 0)
		return (-1);
	if (argv == NULL)
		return (-1);
	buffer = malloc(bufSize);
	if (buffer == NULL)
		return (-1);

	putchar('$');
	putchar(' ');
	charCount = getline(&buffer, &bufSize, stdin);
	if (charCount < 0)
		return (-1);
	array = vect(buffer, charCount);
     	free(buffer);
	free(array);
	return (0);
}


char **vect(char *str, ssize_t n)
{
	char *buffer, *bufPointer, *token, *delim = " ";
	char **args;
	size_t tokenSize = 0;
	int index;

	buffer = malloc(n + 1);
	bufPointer = buffer;
	if (buffer == NULL)
		return (NULL);
	bufPointer = buffer;
	strcpy(buffer, str);
	for (index = 0; *bufPointer != '\0'; bufPointer++)
	{
		if (*bufPointer == *delim)
			tokenSize++;
	}
	args = malloc(sizeof(char *) * (tokenSize + 1));
	token = strtok(buffer, delim);
	index = 0;
	while (token != NULL)
	{
		args[index] = malloc(strlen(token));
		args[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	return (args);
}
