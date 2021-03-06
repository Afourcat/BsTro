/*
** EPITECH PROJECT, 2017
** strin_nb_utils_2.c
** File description:
** Second file containing all functions relatives to manipulating string numbers
*/

#include "utils.h"

static int get_int_size(int nb)
{
	int i = 0;

	while (nb / 10 > 0) {
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

int get_sign(char *str1, char *str2)
{
	if (str1[0] == '-' && str2[0] == '-')
		return (0);
	else if (str1[0] != '-' && str2[0] != '-')
		return (0);
	else
		return (1);
}

char *my_itoa(int nb)
{
	int size = get_int_size(nb);
	char *str = my_calloc(sizeof(char) * (get_int_size(nb) + 1));

	for (int i = 0; i < size; i++, nb /= 10)
		str[i] = INT_TO_CHAR(nb % 10);
	my_revstr(str);
	return (str);
}

int put_in_str(char c, char *str)
{
	int size = my_strlen(str);

	str[size] = c;
	str[size + 1] = ' ';
	return (0);
}
