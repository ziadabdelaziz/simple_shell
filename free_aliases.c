#include "shell.h"

/**
 * free_aliases - frees all aliases
 * @alias_ptr: ptr to head of alias list
 *
 * Return: TRUE
 */
int free_aliases(alias *alias_ptr)
{
	alias *tmp;

	while (alias_ptr != NULL)
	{
		tmp = alias_ptr;
		alias_ptr = alias_ptr->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}

	return (1);
}
