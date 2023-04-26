#include "shell.h"

/**
 * input_err_check - helper function for sanitizer, check for unexpected char
 * @ptr: pointer to area that needs to be checked
 *
 * Return: TRUE if no error, FALSE if error
 */
int input_err_check(char *ptr)
{
	char *iter = ptr;

	iter++;
	if (*ptr == ';' && *iter == *ptr)
	{
		err_message(ptr, NULL);
		return (0);
	}
	if (*iter == *ptr)
		iter++;
	while (*iter == ' ')
		iter++;
	if (*iter == ';' || *iter == '|' || *iter == '&')
	{
		err_message(iter, NULL);
		return (0);
	}

	return (1);
}
