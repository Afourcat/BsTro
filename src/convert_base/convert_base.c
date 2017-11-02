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

char *convert_base(char *str, char *base, char *op_base, int bools)
{
	int sign = 0;
	char *nb;

	if (!bools) {
		if (str[0] == op_base[3]) {
			sign = 1;
			str  = str + 1;
		}
		nb = get_base_to_dec(str, base, op_base);
		return (!sign ? nb : my_dup_without_zero(nb, 1));
	} else {
		if (str[0] == op_base[3]) {
			sign = 1;
			str = str + 1;
		}
		nb = get_dec_to_base(str, base, op_base);
		return (!sign ? nb : add_minus(nb, op_base[3]));
	}
}
