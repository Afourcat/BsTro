/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** Functions used to display
*/

#include <unistd.h>

/**
 * \fn void my_putchar (char c)
 * \brief Function that displays a character on stdout.
 * \param c The character to be displayed.
 */
void my_putchar(char const c)
{
	write(1, &c, 1);
}

/**
 * \fn void my_putstr (char *str)
 * \brief Function that displays a string by calling my_putchar
 * \param str The string to be displayed.
 */
void my_putstr(char const *str)
{
	if (str != NULL && str[0] != '\0') {
		while (*str)
			my_putchar(*str++);
	}
}
