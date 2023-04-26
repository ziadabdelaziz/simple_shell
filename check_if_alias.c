#include "shell.h"
/**
 * check_if_alias - if the alias command is not called, this will check if the
 * command is an alias, and if so replace it with it's value
 * @args: argument to be checked
 * @alias_ptr: points to list of aliases to be checked against
 *
 * Return: TRUE
 */
int check_if_alias(char **args, alias *alias_ptr)
{
	while (alias_ptr != NULL)
	{
		if (_strcmp(*args, alias_ptr->name, 3) == 1)
		{
			*args = _strdup(alias_ptr->value);
			return (7);
		}
		alias_ptr = alias_ptr->next;
	}
	return (1);
}
