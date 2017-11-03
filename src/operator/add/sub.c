/*
** EPITECH PROJECT, 2017
** sub.c
** File description:
** Substraction
*/

#include "utils.h"

void sub_it(char *nb1, char *nb2, char *res, int *sizes)
{
	int current_nbr = 0;
	int retain = 0;
	int i = 0;

	while (sizes[0] >= 0 || sizes[1] >= 0) {
		if (sizes[1] < 0)
			current_nbr = CHAR_TO_INT(nb1[sizes[0]]) - retain;
		else
			current_nbr = CHAR_TO_INT(nb1[sizes[0]]) -
				CHAR_TO_INT(nb2[sizes[1]]) - retain;
		if (current_nbr < 0) {
			current_nbr = CHAR_TO_INT(nb1[sizes[0]]) + 10;
			current_nbr -= (sizes[1] < 0) ? 1 :
				CHAR_TO_INT(nb2[sizes[1]]) + retain;
			retain = 1;
		} else
			retain = 0;
		res[i++] = INT_TO_CHAR(current_nbr);
		sizes[0]--;
		sizes[1]--;
	}
}

int sub(char *nb1, char *nb2, char *res, int sign)
{
	int sizes[] = {my_strlen(nb1) - 1, my_strlen(nb2) - 1};
	int bool_s = 0;

	if (sign < 0 && compare(nb1, nb2) != 0)
		bool_s = 1;
	sub_it(nb1, nb2, res, sizes);
	return (bool_s);
}
