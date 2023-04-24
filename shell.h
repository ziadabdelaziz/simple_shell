#ifndef shell
#define shell

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void get_args(char **arg);
char *add_bin(char *arg);
void exit_shell(char *command, char *staus);
int check_access(char *command);

#endif
