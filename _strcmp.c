#include "shell.h"
/**
 * _strcmp - compare two string
 * @s1: string
 * @s2: string
 * @match: match
 * Return: difference between the 2 strings
 */
int _strcmp(char *s1, char *s2, int match)
{
	if (s1 == NULL || s2 == NULL)
		return (0);

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);

		s1++;
		s2++;
	}

	if (match == 4)
		return (1);

	if (*s1 == *s2)
		return (1);

	return (0);
}
