/*
** EPITECH PROJECT, 2017
** strin_nb_utils_2.c
** File description:
** Second file containing all functions relatives to manipulating string numbers
*/

#include "utils.h"

int get_sign(char *str1, char *str2)
{
	if (str1[0] == '-' && str2[0] == '-')
		return (0);
	else if (str1[0] != '-' && str2[0] != '-')
		return (0);
	else
		return (1);
}

int get_int_size(int nb)
{
	int i = 0;
	
	while (nb / 10 > 0) {
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

char *my_itoa(int nb)
{
 	int size = get_int_size(nb);
	char *str = my_calloc(sizeof(char) * (get_int_size(nb) + 1));
	
	for (int i = 0; i < size; i++, nb/=10)
		str[i] = int_to_char(nb % 10);
	my_revstr(str);
	return (str);
}
