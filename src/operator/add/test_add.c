/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test function for inifinite add
*/

#include <unistd.h>

int test_letter(char *str1);
int test_nbr_arg(int ac);

int my_putstr_error(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		write(2, &str[i], 1);
		i++;
	}
	return (84);
}

int test_signe(char *str)
{
	int i = 0;

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

int error_test(char *str1, char *str2, int ac)
{
	if (test_nbr_arg(ac) == 84)
		return (84);
	if (str1[0] == '\0' || str2[0] == '\0') {
		my_putstr_error("There is an empty string.\n");
		return (84);
	}
	if (test_letter(str1) == 84 || test_letter(str2) == 84)
		return (84);
	return (0);
}

int test_nbr_arg(int ac)
{
	if (ac != 3) {
		my_putstr_error("Not 3 arguments.\n");
		return (84);
	}
	return (0);
}

int test_letter(char *str1)
{
	int i = 0;

	while (str1[i] != '\0') {
		if ((str1[i] < '0' || str1[i] > '9') &&
		    str1[i] != '-' && str1[i] != '+') {
			my_putstr_error("There is a letter inside an argument !\n");
			return (84);
		}
		i++;
	}
	return (0);
}
