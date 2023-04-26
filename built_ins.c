#include "shell.h"

/**
 * built_ins - checks if a command is a built in
 * @args: command and arguments
 *
 * Return: SKIP_FORK if built in, DO_EXECVE if not a built in, EXIT_SHELL if
 * exit shell, EXIT_SHELL_CODE if exiting with a particular code
 */
int built_ins(char **args)
{
	char **args_ptr = args;
	int i;

	while (*args_ptr != NULL)
	{
		if (**args_ptr == '#')
		{
			*args_ptr = NULL;
			break;
		}
		if (_strcmp("~", *args_ptr, 3) == 1
		    && get_array_element(environ, "HOME=") != NULL)
		{
			*args_ptr = _strdup(get_array_element
					(environ, "HOME=") + 5);
			continue;
		}
		if (_strcmp("~/", *args_ptr, 4) == 1
		    && get_array_element(environ, "HOME=") != NULL)
		{
			*args_ptr = _strconcat(get_array_element
					       (environ, "HOME=")
					       + 5, *args_ptr + 1);
		}
		*args_ptr = check_for_vars(*args_ptr);

		args_ptr++;
	}
	if (*args == NULL)
		return (6);

	i = alias_func(args, 0);
	if (i == 7 || i == 6)
		return (i);

	if (_strcmp("exit", *args, 3) == 1 && args[1] != NULL)
	{
		status = _atoi(args[1]);
		if (status < 0)
		{
			status = 2;
			err_message(args[0], args[1]);
			return (6);
		}
	}
	if (_strcmp("exit", *args, 3) == 1)
		return (5);
	else if (_strcmp("setenv", *args, 3) == 1 && args[1] != NULL)
		return (_setenv(args[1], args[2]));
	else if (_strcmp("unsetenv", *args, 3) == 1
		 && args[1] != NULL)
		return (_unsetenv(args[1]));
	else if (_strcmp("cd", *args, 3) == 1)
		return (change_dir(args[1]));
	else if (_strcmp("env", *args, 3) == 1)
		return (print_env());

	return (7);
}

