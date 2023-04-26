#include "shell.h"

int status;

/**
 * _setenv - sets and environmental variable
 * @name: name of the variable
 * @value: value to set the variable to
 *
 * Return: 0 on success
 */
int _setenv(const char *name, const char *value)
{
	char **new_environ;
	char *buffer;
	char *buf_tmp;
	char *element_ptr;
	int len;

	if (value == NULL)
	{
		write(STDERR_FILENO, "setenv: no value given\n", 23);
		status = 2;
		return (6);
	}

	buffer = _strconcat((char *)name, "=");

	element_ptr = get_array_element(environ, buffer);

	buf_tmp = _strconcat(buffer, (char *)value);
	free(buffer);
	buffer = buf_tmp;

	if (element_ptr == NULL)
	{
		len = list_len(environ, NULL);
		new_environ = array_cpy(environ, len + 1);
		new_environ[len - 1] = buffer;
		new_environ[len] = NULL;
		free_array(environ);
		environ = new_environ;
		return (6);
	}

	len = list_len(environ, (char *)name);
	free(environ[len]);
	environ[len] = buffer;

	status = 0;

	return (6);
}
