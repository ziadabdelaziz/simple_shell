#include "shell.h"

/* get_args - string to list of strings
 * @arg: array of strings
 * Return: None
 */
void get_args(char **arg)
{
	int i = 0;
	size_t n = 0;
	char *buf = NULL, del[] = " \n", *token;

	if (getline(&buf, &n, stdin) == -1)
		exit(1);

	for (token = strtok(buf,del); token; token = strtok(NULL, del))
		arg[i++] = token;

	arg[i] = NULL;
}
