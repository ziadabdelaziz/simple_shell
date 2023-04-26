#include "shell.h"
/**
 * array_cpy - copies an array
 * @old_array: array to be copied
 * @new_size: size of new array
 *
 * Return: the new array
 */
char **array_cpy(char **old_array, int new_size)
{
	char **new_array = NULL;
	char **ptr_array;

	new_array = malloc(sizeof(char **) * new_size);

	ptr_array = new_array;
	while (*old_array != NULL)
	{
		*ptr_array = _strdup(*old_array);
		ptr_array++;
		old_array++;
	}
	*ptr_array = NULL;

	return (new_array);
}
