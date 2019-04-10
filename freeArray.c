#include "shell.h"

/**
 * freeArray - frees any double pointer array
 * @arr: Array to be free'd
 *
 * Return: void
 */
void freeArray(char **arr)
{
	int index;

	if (arr == NULL)
		return;
	for (index = 0; arr[index] != NULL; index++)
		free(arr[index]);
	if (arr[index] == NULL)
		free(arr[index]);
	free(arr);
}
