#include "shell.h"

/**
 * and_or - deals with command line logical operators
 * @args: command and arguments
 * @operator: first char of logical operator
 * @last_compare: if last command in logic evaluated to true or false
 *
 * Return: if this command evaluates to true or false
 */
int and_or(char **args, char operator, int last_compare)
{
	int i;

	if (last_compare == 2)
	{
		i = execute_command(args);
		if (i == 5)
			return (5);
		if (i == 1)
			return (1);

		return (0);
	}
	if (last_compare == 1 && operator == '&')
	{
		i = execute_command(args);
		if (i == 5)
			return (5);
		if (i == 1)
			return (1);

		return (0);
	}

	if (last_compare == 0 && operator == '|')
	{
		i = execute_command(args);
		if (i == 5)
			return (5);
		if (i == 1)
			return (1);

		return (0);
	}

	if (last_compare == 1 && operator == '|')
		return (1);

	return (0);
}
