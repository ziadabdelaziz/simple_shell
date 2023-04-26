#include "shell.h"
/**
 * print_aliases - prints all aliases in list
 * @alias_ptr: points to list of aliases
 *
 * Return: SKIP_FORK
 */
int print_aliases(alias *alias_ptr)
{
	while (alias_ptr != NULL)
	{
		write(STDOUT_FILENO, alias_ptr->name, _strlen(alias_ptr->name));
		write(STDOUT_FILENO, "=\'", 2);
		write(STDOUT_FILENO, alias_ptr->value,
		      _strlen(alias_ptr->value));
		write(STDOUT_FILENO, "\'\n", 2);
		alias_ptr = alias_ptr->next;
	}
	return (6);
}
