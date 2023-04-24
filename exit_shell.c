#include "shell.h"

/**
 * exit_shell - exit the shell
 * @command: command
 * @status: status
 * Return: None
 */
void exit_shell(char *command, char *status)
{
	if (strcmp(command, "/bin/exit") == 0)
	{
		if (status)
			exit(_atoi(status));
		else
			exit(0);
	}
}
