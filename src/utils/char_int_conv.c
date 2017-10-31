/*
** EPITECH PROJECT, 2017
** char_int_conv.c
** File description:
** Functions that converts an int to char and reverse
*/

/**
 * \fn char int_to_char (int i)
 * \brief Function that converts an int into a char by adding 48 to
 * it's value
 * \param i The integer to be converted.
 * \return The character converted from the integer.
 */
char int_to_char(int i)
{
	return (i + 48);
}

/**
 * \fn char char_to_int (char c)
 * \brief Function that converts an char into a int by retrieving 48 to
 * it's value
 * \param c The char to be converted.
 * \return The int converted from the char.
 */
int char_to_int(char c)
{
	return (c - 48);
}
