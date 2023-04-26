#include "shell.h"
/**
 * _strconcat - concatenates two strings
 * @s1: string
 * @s2: string
 * Return: a pointer to the new string || NULL
 */
char *_strconcat(char *s1, char *s2)
{
	int len = _strlen(s1) + _strlen(s2);
	char *dest = malloc(len + 1);
	char *ptr = dest;

	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr = *s1;
			ptr++;
			s1++;
		}
	}
	if (s2 != NULL)
	{
		while (*s2 != '\0')
		{
			*ptr = *s2;
			ptr++;
			s2++;
		}
	}

	*ptr = '\0';
	return (dest);
}
