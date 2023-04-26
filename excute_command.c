#include "shell.h"

/**
 * execute_command - executes a command
 * @args: command and arguments
 *
 * Return: TRUE or EXIT_SHELL
 */
int execute_command(char **args)
{
	char *buf_ptr = *args;
	char *command_name;
	pid_t pid;
	int what_do = built_ins(args);

	if (what_do == 7)
	{
		command_name = check_command(args);
		if (command_name == NULL)
			return (0);

		pid = fork();
		if (pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execve(command_name, args, environ);
			exit(EXIT_FAILURE);
		}
		wait(&status);
		free(command_name);
		fflush(stdin);
		if (status != 0)
		status = 2;
	}
	if (_strcmp("false", *args, 3) == 1)
		status = 1;

	if (*args != buf_ptr)
		free(*args);
	args++;

	while (*args != NULL)
	{
		while (*buf_ptr != '\0')
			buf_ptr++;
		buf_ptr++;
		if (*args != buf_ptr)
			free(*args);
		args++;
	}
	if (what_do == 5)
		return (5);

	if (status != 0)
		return (0);
	return (0);
}
