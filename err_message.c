#include "shell.h"
/**
 * err_message - prints error messages and sets status
 * @arg0: command that is causing error
 * @arg1: first argument to command
 */
void err_message(char *arg0, char *arg1)
{
	char *err_str_num = _itoa(line_num);

	write(STDERR_FILENO, sh_name, _strlen(sh_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_str_num, _strlen(err_str_num));
	free(err_str_num);

	if (_strcmp("cd", arg0, 3) == 1)
	{
		status = 2;
		write(STDERR_FILENO, ": cd: can't cd to ", 18);
		write(STDERR_FILENO, arg1, _strlen(arg1));
		write(STDERR_FILENO, "\n", 1);
		return;
	}

	if (_strcmp("exit", arg0, 3) == 1)
	{
		write(STDERR_FILENO, ": exit: Illegal number: ", 24);
		write(STDERR_FILENO, arg1, _strlen(arg1));
		write(STDERR_FILENO, "\n", 1);
		return;
	}
	if (*arg0 == ';' || *arg0 == '|' || *arg0 == '&')
	{
		status = 2;
		write(STDERR_FILENO, ": Syntax error: \"", 17);
		write(STDERR_FILENO, arg0, 1);
		if (*arg0 == *(arg0 + 1))
			write(STDERR_FILENO, arg0, 1);
		write(STDERR_FILENO, "\" unexpected\n", 14);
		return;
	}

	status = 127;
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg0, _strlen(arg0));
	write(STDERR_FILENO, ": not found\n", 12);
}

