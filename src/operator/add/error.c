/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** Errors functions
*/

#include <unistd.h>
#include <infin_add.h>

void my_putchar_error(char c)
{
	write(2, &c, 1);
}

void my_putstr_error(char *str)
{
	while (*str) {
		my_putchar_error(*str);
		str++;
	}
}

int is_only_num(char *str)
{
	while (*str) {
		if ((*str < '0' || *str > '9') && *str != '-') {
			return (1);
		}
		str++;
	}
	return (0);
}

int check(int argc, char **argv)
{
	if (argc != 3) {
		my_putstr_error("Error: You must give 2 arguments.\n");
		return (84);
	}
	if (my_strlen(argv[1]) == 0 || my_strlen(argv[2]) == 0) {
		my_putstr_error("Error: Empty strings are not authorized.\n");
		return (84);
	}
	if (is_only_num(argv[1]) == 1 || is_only_num(argv[2]) == 1) {
		my_putstr_error("Error: Only numbers and - authorized.\n");
		return (84);
	}
	return (0);
}
