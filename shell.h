#ifndef shell
#define shell

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void get_args(char **arg);
char *add_bin(char *arg);
void exit_shell(char **command);
int check_access(char *command);
int _atoi(char *str);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);

#endif
