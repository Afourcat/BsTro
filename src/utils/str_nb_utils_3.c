/*
** EPITECH PROJECT, 2017
** str_nb_utils.c
** File description:
** 3th utils file
*/

#include "utils.h"

int get_str_nb(char *str, char *to_return, int *i, char *nb_base)
{
	int size = my_strlen(to_return);

	while (is_in(str[*i], nb_base)) {
		to_return[size] = str[*i];
		size++;
		(*i)++;
	}
	(*i)--;
	to_return[size] = ' ';
	return (0);
}

char *my_alo(char *str, char *operands)
{
	char *to_return;
	int counter = 0;
	int size_counter = 0;

	while (str[counter]) {
		if (!(str[counter] == operands[0] ||
		      str[counter] == operands[1]))
			size_counter++;
		counter++;
	}
	to_return = my_calloc(sizeof(char) * (size_counter * 2 + 1));
	return (to_return);
}
