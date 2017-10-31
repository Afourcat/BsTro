/*
** EPITECH PROJECT, 2017
** convert_base.c
** File description:
** Main file for the base converter
*/

#include "utils.h"
#include "convert_base.h"

static char *add_minus(char *str, char neg)
{
	str = my_revstr(str);
	str[my_strlen(str)] = neg;
	str = my_revstr(str);
	return (str);
}

/**
 * \fn char* convert_base (char *str, char *base, char neg, int bools)
 * \brief Function that converts a string from a base to another base.
 * \param str The string to be converted.
 * \param base The base in which or from the string has to be converted
 * \param neg The character that acts as a negative character
 * \param bools A boolean that tells the function if it should convert from
 * base to dec (0), or from dec to base (1).
 * \return The converted string.
 */
char *convert_base(char *str, char *base, char neg, int bools)
{
	int sign = 0;
	char *nb;

	if (!bools) {
		if (str[0] == neg) {
			sign = 1;
			str  = str + 1;
		}
		nb = get_base_to_dec(str, base);
		return (!sign ? nb : my_dup_without_zero(nb, 1));
	} else {
		if (str[0] == '-') {
			sign = 1;
			str = str + 1;
		}
		nb = get_dec_to_base(str, base);
		return (!sign ? nb : add_minus(nb, neg));
	}
}
