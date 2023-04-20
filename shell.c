#include "shell.h"
int main(void)
{

	while(1){
		size_t pid;
		
		char **arg, bin[100] = "/bin/";
		arg=malloc(sizeof(char *)*40);
		printf("┌──(Myshell㉿ALX)-[~]\n└─$ ");
	
		get_args(arg);

		if (!(arg[0][0]=='/'&&arg[0][1]=='b'))
                             strcat(bin,arg[0]);
		if (access(bin, X_OK) == -1)
		{
			printf("NOT FOUND\n");
			continue;
		}
		pid = fork(); 
		if (strcmp(arg[0],"exit") == 0)
			return 0;
		if (pid == 0){
			if (arg[0][0]=='/'&&arg[0][1]=='b'){
				execve(arg[0],arg,NULL);
			}
			else
			{
				execve(bin,arg,NULL);
			}
		}
		wait(NULL);
	}
	return 0;
}
