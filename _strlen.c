#include "shell.h"
/**
 * _strlen - get length of string
 * @str: string
 * Return: the length of the str.
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{}
	return (i);
}
