#include "shell.h"
/**
 * free_array - frees a two dimensional array
 * @args: array to be freed
 *
 * Return: TRUE
 */
int free_array(char **args)
{
	char **ptr = args;

	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}

	free(args);

	return (1);
}
