#include "shell.h"

/**
 * exit_shell - exit the shell
 * @command: command
 * @status: status
 * Return: None
 */
void exit_shell(char **command)
{
	int status;

	printf("%s", command[0]);
	if (_strcmp(command[0], "/bin/exit") == 0)
	{
		if (command[1])
		{
			status = _atoi(command[1]);
			free(command);
			exit(status);
		}
		else
		{
			free(command);
			exit(0);
		}
	}
}
