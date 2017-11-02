/*
** EPITECH PROJECT, 2017
** infin_add.c
** File description:
** Function used to add two representation of numbers in string
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_add.h"

int get_sign_add(char **str, char *op_base)
{
	if (str[0][0] == op_base[3]) {
		*str = str[0] + 1;
		return (-1);
	}
	return (1);
}

void add_it(char *nb1, char *nb2, char *res)
{
	int size_nb1 = my_strlen(nb1) - 1;
	int size_nb2 = my_strlen(nb2) - 1;
	int retain = 0;
	int current_nbr = 0;
	int i = 0;

	while (size_nb1 >= 0 || size_nb2 >= 0) {
		if (size_nb1 < 0) {
			current_nbr = char_to_int(nb2[size_nb2--]) + retain;
		} else if (size_nb2 < 0) {
			current_nbr = char_to_int(nb1[size_nb1--]) + retain;
		} else {
			current_nbr = char_to_int(nb1[size_nb1--]) +
				char_to_int(nb2[size_nb2--]) + retain;
		}
		retain = current_nbr / 10;
		current_nbr %= 10;
		res[i++] = int_to_char(current_nbr);
	}
	if (retain != 0)
		res[i] = int_to_char(retain);
}

static void free_add(char *nb1, char *nb2, int sign_nb1, int sign_nb2)
{
	if (sign_nb1 < 0)
		free(nb1 - 1);
	else
		free(nb1);
	if (sign_nb2 < 0)
		free(nb2 - 1);
	else
		free(nb2);
}

int infin_add_wrapped(char **nb1, char **nb2, char *res, char *op_base)
{
	int sign_nb1 = get_sign_add(nb1, op_base);
	int sign_nb2 = get_sign_add(nb2, op_base);
	int bool_s = 0;

	if (sign_nb1 == -1 && sign_nb2 == -1) {
		bool_s = (nb1[0][0] == '0' && nb2[0][0] == '0') ? 0 : 1;
		add_it(*nb1, *nb2, res);
	} else if (sign_nb1 == -1 || sign_nb2 == -1) {
		if (compare(*nb1, *nb2) == 1)
			bool_s = sub(*nb1, *nb2, res, sign_nb1);
		else
			bool_s = sub(*nb2, *nb1, res, sign_nb2);
	} else
		add_it(*nb1, *nb2, res);
	free_add(*nb1, *nb2, sign_nb1, sign_nb2);
	return (bool_s);
}

char *infin_add(char *nb1, char *nb2, char *op_base)
{
	int size_nb1 = my_strlen(nb1);
	int size_nb2 = my_strlen(nb2);
	int size_res = (size_nb1 > size_nb2) ? size_nb1 : size_nb2;
	char *res = my_calloc(sizeof(char) * (size_res + 2));
	int bool_s = infin_add_wrapped(&nb1, &nb2, res, op_base);

	my_revstr(res);
	return (my_dup_without_zero(res, bool_s));
}
