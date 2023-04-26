#include "shell.h"
/**
 * _strdup - mem. alloc for a copy of a string
 * @src: source
 * Return: a pointer to the dest. || NULL
 */
char *_strdup(char *src)
{
	int len = _strlen(src);
	char *dest = malloc(len + 1);
	char *ptr;

	if (dest == NULL)
		exit(EXIT_FAILURE);
	ptr = dest;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}
