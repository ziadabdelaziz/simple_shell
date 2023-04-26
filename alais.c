#include "shell.h"

/**
 * alias_func - deals with command aliases
 * @args: arguments from command line
 * @to_free: indicated if aliases need to be freed (exiting shell);
 *
 * Return: TRUE if exiting, FALSE if the command is not "alias" or an alias,
 * SKIP_FORK if success
 */
int alias_func(char **args, int to_free)
{
	static alias head = {NULL, NULL, NULL};
	char *char_ptr;
	int no_error = 1;

	if (to_free == 1)
		return (free_aliases(head.next));

	if (_strcmp("alias", *args, 3) != 1)
		return (check_if_alias(args, head.next));

	args++;

	if (*args == NULL)
		return (print_aliases(head.next));

	while (*args != NULL)
	{
		char_ptr = *args;
		while (*char_ptr != '\0' && *char_ptr != '=')
			char_ptr++;

		if (*char_ptr == '\0' || char_ptr == *args)
		{
			if (print_alias_value(*args, &head) == 0)
				no_error = 0;
		}
		else
		{
			*char_ptr = '\0';
			char_ptr++;
			set_alias_value(*args, &head, char_ptr);
			*(char_ptr - 1) = '=';
		}
		args++;
	}

	if (no_error == 0)
		return (6);

	status = 0;
	return (6);
}
