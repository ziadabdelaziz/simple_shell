#include "shell.h"

/**
 * check_access - check if command is available
 * Return: 1 if command is available
 * 0 if command is not available
 */
int check_access(char *command)
{
	if (access(command, X_OK) == -1)
	{
		printf("NOT FOUND\n");
		return (0);
	}

	return (1);
}
