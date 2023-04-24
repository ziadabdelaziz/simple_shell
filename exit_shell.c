#include "shell.h"

/**
 * exit_shell - exit the shell
 * Return: None
 */
void exit_shell(char *command, char *status)
{
	if (strcmp(command, "/bin/exit") == 0)
	{
		if (status)
			exit(atoi(status));
		else
			exit(0);
	}
}
