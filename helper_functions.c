#include "shell.h"

/**
 * _strlen - get the length of a string
 * @s:  pointer to beginning of string
 * Return: returns string length
 **/
int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
	{
		s++;
	}
	return (i);
}

/**
 * strlen_const - length of constant string
 * @string: pointer to find the length
 * Return: length of string
 **/
unsigned int strlen_const(const char *string)
{
	unsigned int n;

	while (*string)
	{
		string++;
	}
	return (n);
}


/**
 * _strcpy - copy string
 * @dest: destination pointer
 * @src: source
 * @n: number bytes
 * Return: returns char ptr
 **/

char *_strcpy(char *dest, char *src, int n)
{
	int index = 0;

	while (index < n && src[index] != '\0')
	{
		index++;
		dest[index] = src[index];
	}

	while (index < n)
	{
		index++;
		dest[index] = '\0';
	}

	return (dest);
}


/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: returns 1 on success
 **/
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}
	return (1);
}

/**
* _strncpy - compies one string to another string in memory
* @dest: destination of string to copy from
* @src: string to copy
* @n: length of the copied string
* Return: memory of copied string
**/
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *src != '\0')
	{
		*dest = *src;
		i++;
	}

	while (i < n)
	{
		*dest = '\0';
		i++;
	}
	return (dest);
}
