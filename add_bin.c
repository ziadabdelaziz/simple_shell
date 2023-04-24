#include "shell.h"

/**
 * add_bin - add /bin/ if does not exist
 * Return: None
 */
char *add_bin(char *arg)
{
	char bin[100] = "/bin/";

	if (!(arg[0] == '/' && arg[1] == 'b'))
	{
		strcat(bin, arg);
		arg = bin;
	}
	return (arg);
}
