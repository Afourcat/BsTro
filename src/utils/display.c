/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** Functions used to display
*/

#include <unistd.h>

void my_putchar(char const c)
{
	write(1, &c, 1);
}

void my_putstr(char const *str)
{
	while (*str)
		my_putchar(*str++);
}
