#include "shell.h"
/**
 * check_for_vars - checks an argument to see if it is a variable and if so,
 * replaces it with it's value
 * @arg: argument to be checked
 *
 * Return: a pointer to the evaluated argument (either new or an altered clone)
 */
char *check_for_vars(char *arg)
{
	char *clone = NULL;
	char *ptr = arg;
	char *next;
	char *tmp;
	char *buffer;
	int is_var;
	int i;

	while (*ptr != '\0')
	{
		if (*ptr == '$')
		{
			if (clone == NULL)
			{
				clone = _strdup(arg);
				i = ptr - arg;
				ptr = clone + i;
			}
			next = ptr + 1;
			while (*next != '\0' && *next != '$' && *next != '#')
				next++;

			if (*next == '$' && next > ptr + 1)
				is_var = 1;
			else if (*next == '#')
				is_var = 2;
			else
				is_var = 0;

			*next = '\0';

			if (_strcmp("$?", ptr, 3) == 1)
				tmp = _itoa(status);
			else if (_strcmp("$0", ptr, 3) == 1)
				tmp = _strdup(sh_name);
			else if (get_array_element(environ, ptr + 1) != NULL)
			{
				buffer = _strconcat(ptr + 1, "=");
				tmp = _strdup(get_array_element
				(environ, buffer) + _strlen(buffer));
				free(buffer);
			}
			else
				tmp = _strdup("");

			*ptr = '\0';
			ptr = _strconcat(clone, tmp);
			free(tmp);
			if (is_var == 0)
			{
				free(clone);
				clone = ptr;
				break;
			}
			if (is_var == 1)
				*next = '$';
			else if (is_var == 2)
				*next = '#';
			tmp = _strconcat(ptr, next);
			free(ptr);
			ptr = tmp;
			free(clone);
			clone = ptr;
			if (is_var == 2)
			{
				while (*ptr != '#')
					ptr++;
			}
		}
		ptr++;
	}
	if (clone != NULL)
		return (clone);

	return (arg);
}
