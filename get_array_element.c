#include "shell.h"

/**
 * get_array_element - gets an element of an array
 * @array: array to be searched
 * @element_name: name of element to be found
 *
 * Return: the array element, or NULL if it is not found
 */
char *get_array_element(char **array, char *element_name)
{
	while (*array != NULL)
	{
		if (_strcmp(*array, element_name, 4) == 1)
			return (*array);

		array++;
	}

	return (NULL);
}
