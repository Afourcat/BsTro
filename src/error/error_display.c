 /*
 ** EPITECH PROJECT, 2017
 ** error_display.c
 ** File description:
 ** Functions to display errors
 */

#include <unistd.h>

void my_putchar_error(char c)
{
	write(2, &c, 1);
}

int my_putstr_error(char *str)
{
	while (*str) {
		my_putchar_error((*str)++);
}
