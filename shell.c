#include "shell.h"

/**
 * main - program starting point
 * Return: 0
 */
int main(void)
{

	while (1)
	{
		size_t pid;
		char **arg;

		arg = malloc(sizeof(char *) * 40);
		if (arg == NULL)
			exit(1);

		printf("Theshell$ ");

		get_args(arg);
		arg[0] = add_bin(arg[0]);

		exit_shell(arg[0], arg[1]);
		if (!check_access(arg[0]))
			continue;

		pid = fork();
		if (pid == 0)
		{
			execve(arg[0], arg, environ);
		}
		wait(NULL);
	}
	return (0);
}
