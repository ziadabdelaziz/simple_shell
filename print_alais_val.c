#include "shell.h"

/**
 * print_alias_value - prints the value of a particular alias
 * @arg: name of alias
 * @alias_ptr: points to list of aliases
 *
 * Return: TRUE if valid alias, FALSE if not
 */
int print_alias_value(char *arg, alias *alias_ptr)
{
	while (alias_ptr != NULL)
	{
		fflush(stdin);
		if (_strcmp(arg, alias_ptr->name, 3) == 1)
		{
			write(STDOUT_FILENO, arg, _strlen(arg));
			write(STDOUT_FILENO, "=\'", 2);
			write(STDOUT_FILENO, alias_ptr->value,
			      _strlen(alias_ptr->value));
			write(STDOUT_FILENO, "\'\n", 2);
			return (1);
		}
		alias_ptr = alias_ptr->next;
	}

	status = 1;
	write(STDERR_FILENO, "alias: ", 7);
	write(STDERR_FILENO, arg, _strlen(arg));
	write(STDERR_FILENO, " not found\n", 11);

	return (0);
}
