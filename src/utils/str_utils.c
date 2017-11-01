/*
** EPITECH PROJECT, 2017
** str_utils
** File description:
** Utility functions for manipulatins str
*/

#include <stdlib.h>

/**
 * \fn int my_strlen(char const *str)
 * \brief Function that compute the length of the str passed as parameter.
 * \param str The string which length as to be computed.
 * \return The length of the string passed as parameter.
 */
int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * \fn char *my_strcat(char *dest, char const *src)
 * \brief Function that concatenate two strings and returns the result.
 * \param dest The destination string, it will be returned after concatenation.
 * \param src The string which has to be concatenate into dest.
 * \return The concatenated string , passed as parameter as dest.
 */
char *my_strcat(char *dest, char const *src)
{
	int counter = 0;
	int dest_counter = 0;

	while (dest[dest_counter])
		dest_counter++;
	while (src[counter]) {
		dest[dest_counter + counter] = src[counter];
		counter++;
	}
	return (dest);
}

/**
 * \fn int is_in(char c, char *str)
 * \brief Function that search if a character is contained into a string
 * and returns it's position (0 if not found).
 * \param c The character which is searched for.
 * \param str The string in which we are searching.
 * \return The position of the character in string (0 if not found).
 */
int is_in(char c, char *str)
{
	int counter = 0;

	while (str[counter]) {
		if (c == str[counter])
			return (counter + 1);
		counter++;
	}
	return (0);
}

/**
 * \fn int remove_whitespace(char *str)
 * \brief Function that removes whitespace in a string.
 * \param str The string in which we have to remove whitespace.
 * \return EXIT_SUCCESS.
 */
int remove_whitespace(char *str)
{
	int counter = 0;
	int offset = 0;

	while (str[counter + offset]) {
		if (str[counter + offset] == ' ')
			offset++;
		str[counter] = str[counter + offset];
		counter++;
	}
	while (str[counter]) {
		str[counter] = 0;
		counter++;
	}
	return (0);
}

/**
 * \fn char *my_revstr(char *str)
 * \brief Function that reverse a string and returns it.
 * \param str The string to be reversed.
 * \return The string which has been reversed.
 */
char *my_revstr(char *str)
{
       	char buffer = 0;
	int size = my_strlen(str) - 1;

	if (str == NULL || str[0] == '\0')
		return (str);
	for (int i = 0; i  <= size / 2; i++){
		buffer = str[i];
		str[i] = str[size - i];
		str[size - i] = buffer;
	}
	return (str);
}
