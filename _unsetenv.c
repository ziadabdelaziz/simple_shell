#include "shell.h"

/**
 * _unsetenv - deletes an environmental variable
 * @name: name of variable
 *
 * Return: 0 if successful
 */
int _unsetenv(const char *name)
{
	char **env_ptr;
	char *buffer;
	int len;

	buffer = _strconcat((char *)name, "=");
	len = list_len(environ, buffer);
	free(buffer);

	if (len == -1)
	{
		write(STDERR_FILENO, "unsetenv: variable not found\n", 29);
		status = 2;
		return (6);
	}

	env_ptr = environ + len;
	free(*env_ptr);
	while (*(env_ptr + 1) != NULL)
	{
		*env_ptr = *(env_ptr + 1);
		env_ptr++;
	}
	*env_ptr = NULL;
	status = 0;

	return (6);
}
