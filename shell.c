#include "shell.h"
/**
 * main - mian
 * Return: 0
 */
int main(void)
{
	// ls         /bin/ls

	while (1)
	{
		size_t pid;

		char **arg, bin[100] = "/bin/";

		arg = malloc(sizeof(char *) * 40);
		printf("┌──(Myshell㉿ALX)-[~]\n└─$ ");

		get_args(arg);

		arg[0] = add_bin(arg[0]);

		if (access(arg[0], X_OK) == -1)
		{
			printf("NOT FOUND\n");
			continue;
		}
		pid = fork();
		if (strcmp(arg[0], "exit") == 0)
			return (0);
		if (pid == 0)
		{
			execve(arg[0], arg, NULL);
		}
		wait(NULL);
	}
	return (0);
}
