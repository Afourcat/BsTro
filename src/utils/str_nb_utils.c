/*
** EPITECH PROJECT, 2017
** str_nb_utils
** File description:
** Functions that helps manipulating string numbers
*/

#include <stdlib.h>
#include <utils.h>

/**
 * \fn char *get_opposed_number (char *nb)
 * \brief Function that get the opposed of the number passed as parameter.
 * \param nb The string number which opposed has to be returned.
 * \return The opposed of the number passed as argument.
 */
char *get_opposed_number(char *nb)
{
	if (nb[0] == '-')
		nb = my_dup_without_zero(nb, 0);
	else
		nb = my_dup_without_zero(nb, 1);
	return (nb);
}

/**
 * \fn char *my_allocate(char *str, int bool)
 * \brief Function that reallocate memory basing on the real number it is
 * without beginning 0.
 * \param str The number which has to be reallocated
 * \param bools Boolean telling whether or not the reallocated string
 * should contain sufficient memory for putting a minus sign.
 * \return The pointer on the first byte of the newly allocated string.
 */
char *my_allocate(char *str, int bools)
{
	int size = 1;
	int j = 0;
	char *new_str;

	while (str[j] == '0' && str[j + 1] != '\0')
		j++;
	while (str[j]) {
		j++;
		size++;
	}
	new_str = my_calloc(sizeof(char) * (size + bools));
	return (new_str);
}

/**
 * \fn char *my_dup_without_zero (char *str, int bools)
 * \brief Function that duplicate the string passed as parameter, removing all
 * beginning zeros.
 * \param str The string to be duplicated.
 * \param bools A boolean telling wheter or not the new string should be
 * prefixed by a minus
 * \return The newly duplicated string, without beginning zeros.
 */
char *my_dup_without_zero(char *str, int bools)
{
	char *new_str = my_allocate(str, bools);
	int i = 0;
	int j = 0;

	if (bools == 1) {
		new_str[0] = '-';
		i = 1;
	}
	while (str[j] == '0' && str[j + 1] != '\0') {
		j++;
	}
	while (str[j]) {
		new_str[i] = str[j];
		i++;
		j++;
	}
	free(str);
	return (new_str);
}

/**
 * \fn char *remove_minus(char *str)
 * \brief Function that remove the prefixed minus of a string if any.
 * \param str The string that needs (or not) to remove it's prefixed minus..
 * \return The duplicated string without it's prefixed minus if any.
 */
char *remove_minus(char *str)
{
	char *new_str;
	int j = 0;
	int i = 0;
	
	if (str[0] == '-')
		return (str);
	else
		new_str = my_calloc(my_strlen(str) + 1);
	while (str[i] != '\0') {
		if (str[i] != '-') {
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

/**
 * \fn int compare(char *str1, char *str2)
 * \brief Function that compare two positives string numbers and returns
 * if equal (0), greater than (1) or less than (2).
 * \param str1 The first string to be compared.
 * \param str2 The second string to be compared.
 * \return An integer specifying if they're equals (0), greater than (1)
 * or less than (2).
 */
int compare(char *str1, char *str2)
{
	int i = 0;

	if (my_strlen(str2) == my_strlen(str1)) {
		while (str1[i] == str2[i] && i < my_strlen(str1)) {
			i++;
		}
		if (i == my_strlen(str1))
			return (0);
		return (str1[i] > str2[i] ? 1 : 2);
	}
	return (my_strlen(str1) > my_strlen(str2) ? 1 : 2);
}
