/*
** EPITECH PROJECT, 2017
** error_display.c
** File description:
** Functions to display errors
*/

#include <unistd.h>

/**
 * \fn void my_putchar_error (char c)
 * \brief Function that displays the character c on the STDERR.
 * \param c The char to be displayed.
 */
void my_putchar_error(char c)
{
	write(2, &c, 1);
}

/**
 * \fn int my_putstr_error (char *str)
 * \brief Function that displays a string, characters by characters usig
 * my_putchar_error.
 * \param str The string to be displayed.
 * \return EXIT_SUCCESS.
 */
int my_putstr_error(char *str)
{
	if (str != NULL && str[0] != '\0') {
		while (*str)
			my_putchar_error(*str++);
	}
	return (0);
}
