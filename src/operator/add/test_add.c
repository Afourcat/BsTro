/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test function for inifinite add
*/

#include <unistd.h>

int test_signe(char *str)
{
	int i = 1;

	if (str[0] == '-')
		return (-1);
	while(str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == '-') {
			return (-1);
		}
		else if (str[i] >= '0' && str[i] <= '9' && str[i - 1] != '-') {
			return (1);
		}
		i++;
	}
	return (0);
}
