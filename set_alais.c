#include "shell.h"
/**
 * set_alias_value - initializes an alias or resets its value if it exists
 * @arg: name of alias
 * @alias_ptr: pointer to list of aliases
 * @new_value: value of alias to be set
 *
 * Return: TRUE
 */
int set_alias_value(char *arg, alias *alias_ptr, char *new_value)
{
	while (alias_ptr->next != NULL
	       && _strcmp(alias_ptr->name, arg, 3) != 1)
	{
		alias_ptr = alias_ptr->next;
	}

	if (_strcmp(alias_ptr->name, arg, 3) == 1)
		free(alias_ptr->value);
	else
	{
		alias_ptr->next = malloc(sizeof(alias *));
		alias_ptr = alias_ptr->next;
		if (alias_ptr == NULL)
			exit(EXIT_FAILURE);

		alias_ptr->name = _strdup(arg);
		alias_ptr->next = NULL;
	}
	alias_ptr->value = _strdup(new_value);

	return (1);
}
