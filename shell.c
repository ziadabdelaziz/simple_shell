#include "shell.h"
/**
 * main - executes commands from the terminal
 * @ac: number of inputs from main
 * @av: array of inputs from main
 *
 * Return: 0, or another number if desired
 */
int main(int argc, char **argv)
{
	(void)argc;
	int bytes_read, is_separated = 0, i;
	size_t buf_size = 1;
	char *buf = NULL, *buf_ptr, *tmp;
	char **args = NULL;

	sh_name = _strdup(*argv);

	environ = array_cpy(environ, list_len(environ, NULL));

	signal(SIGINT, SIG_IGN);

	buf = malloc(1);
	if (buf == NULL)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (is_separated == 0)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "$ ", 3);
			bytes_read = getline(&buf, &buf_size, stdin);
			if (bytes_read == -1)
				break;
			if (bytes_read == 1)
			{
				line_num++;
				continue;
			}
			buf[bytes_read - 1] = '\0';
			buf = input_san(buf, &buf_size);
			if (buf_size == 0)
			{
				line_num++;
				continue;
			}
			buf_ptr = buf;
		}
		else
			buf_ptr = tmp;

		tmp = NULL;
		args = make_array(buf_ptr, ' ', &tmp);
		if (tmp != NULL)
			is_separated = 1;
		else
			is_separated = 0;
		i = command_manager(args);
		free(args);
		if (is_separated == 0)
			line_num++;

		if (i == 5)
			break;
	}
	free(buf);
	alias_func(NULL, 1);
	free_array(environ);
	free(sh_name);
	return (status % 256);
}
