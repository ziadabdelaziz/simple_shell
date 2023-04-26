#include "shell.h"
/**
 * check_command - checks if a non-built-in exists
 * @args: argument and commands
 *
 * Return: TRUE if valid command, FALSE if not
 */
char *check_command(char **args)
{
	char *command_buf;
	char *full_buf;
	char *path_str = NULL;
	char *path_ptr;
	char *path_tmp;
	char **path_var = NULL;
	char **path_var_ptr;

	if (access(*args, X_OK) == 0)
		return (_strdup(*args));

	if (get_array_element(environ, "PATH=") != NULL)
		path_str = _strdup(get_array_element(environ, "PATH=") + 5);

	path_ptr = path_str;

	if (path_str != NULL)
	{
		if (*path_str == ':')
		{
			command_buf = _strconcat("./", *args);
			if (access(command_buf, X_OK) == 0)
			{
				free(path_str);
				return (command_buf);
			}
			else
			{
				free(command_buf);
				path_ptr = _strdup(path_str + 1);
				free(path_str);
				path_str = path_ptr;
			}
		}
		while (*path_ptr != '\0')
		{
			if (*path_ptr == ':' && *(path_ptr + 1) == ':')
			{
				*(path_ptr + 1) = '\0';
				path_tmp = (_strconcat(path_str, ".:"));
				path_ptr = _strconcat(path_tmp, path_ptr + 2);
				free(path_str);
				free(path_tmp);
				path_str = path_ptr;
			}
			path_ptr++;
		}
	}
	if (path_str != NULL)
		path_var = make_array(path_str, ':', NULL);

	path_var_ptr = path_var;

	command_buf = _strconcat("/", *args);

	full_buf = _strdup(command_buf);

	if (path_var != NULL)
	{
		while (*path_var_ptr != NULL && access(full_buf, X_OK) != 0)
		{
			free(full_buf);
			full_buf = _strconcat(*path_var_ptr, command_buf);
			path_var_ptr++;
		}
	}

	free(command_buf);
	free(path_str);
	free(path_var);

	if (access(full_buf, X_OK) != 0)
	{
		err_message(args[0], NULL);
		free(full_buf);
		return (NULL);
	}

	return (full_buf);
}
