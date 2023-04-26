#include "shell.h"
/**
 * command_manager - manages the process a command goes through to get executed
 * @args: command and arguments
 *
 * Return: TRUE if success, FALSE if failure
 */
int command_manager(char **args)
{
	char **args_ptr = args;
	int prev_eval = 2;
	int no_err = 1;
	char prev_op = 'c';
	char next_op = 'c';
	int what_do;

	while (*args != NULL && prev_eval != 5)
	{
		while (*args_ptr != NULL && **args_ptr != '&'
		       && **args_ptr != '|')
			args_ptr++;

		if (_strcmp(*args_ptr, "||", 3) == 1)
		{
			*args_ptr = NULL;
			args_ptr++;
			next_op = '|';
		}
		if (_strcmp(*args_ptr, "&&", 3) == 1)
		{
			*args_ptr = NULL;
			args_ptr++;
			next_op = '&';
		}
		if (next_op == 'c')
			break;

		prev_eval = and_or(args, prev_op, prev_eval);
		if (prev_eval == 0)
			no_err = 0;
		prev_op = next_op;
		args = args_ptr;
	}
	if (next_op == 'c')
	{
		what_do = execute_command(args);

		if (what_do == 5)
			return (5);
	}

	if (no_err == 0 || what_do == 0)
		return (0);

	return (1);
}
