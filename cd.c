#include "shell.h"
/**
 * change_dir - changes the current working directory
 * @name: name of directory to change to
 *
 * Return: 0 if successful
 */
int change_dir(char *name)
{
	char *home;
	char *pwd;
	char old_path_buffer[PATH_MAX];
	char new_path_buffer[PATH_MAX];
	size_t buf_size = PATH_MAX;
	int i;

	getcwd(old_path_buffer, buf_size);

	if (name == NULL)
	{
		home = get_array_element(environ, "HOME=");
		if (home == NULL)
		{
			status = 2;
			err_message("cd", name);
			return (6);
		}

		home += 5;

		i = chdir((const char *)home);
		if (i != -1)
			_setenv("PWD", (const char *)home);
	}
	else if (_strcmp("-", name, 3) == 1)
	{
		pwd = get_array_element(environ, "OLDPWD=");
		if (pwd == NULL)
		{
			status = 2;
			err_message("cd", name);
			return (6);
		}

		pwd += 7;

		i = chdir((const char *)pwd);
		if (i != -1)
		{
			write(STDOUT_FILENO, pwd, _strlen(pwd));
			write(STDOUT_FILENO, "\n", 1);
			_setenv("PWD", (const char *)pwd);
		}
	}
	else if (name != NULL)
	{
		i = chdir((const char *)name);
		if (i != -1)
			_setenv("PWD", getcwd(new_path_buffer, buf_size));
	}
	if (i == -1)
	{
		status = 2;
		err_message("cd", name);
		return (6);
	}

	status = 0;
	_setenv("OLDPWD", (const char *)old_path_buffer);

	return (6);
}
