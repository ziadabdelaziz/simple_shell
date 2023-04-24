#include "shell.h"
/**
 * _atoi - string to int
 * @str: str
 * Return: int
 */
int _atoi(char *str)
{
	int i = 0, res = 0, pow = 1;

	for (i = 0; str[i] != '\0'; i++)
	{}
	i--;
	for (; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res += (pow * (str[i] - '0'));
			pow *= 10;
		}
		else
			return (res);
	}
	return (res);
}
