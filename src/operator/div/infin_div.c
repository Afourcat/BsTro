/*
** EPITECH PROJECT, 2017
** infin_div.c
** File description:
** infinite multiplication functions
*/

#include <stdlib.h>
#include <utils.h>
#include <error.h>
#include <infin_add.h>
#include <infin_sub.h>
#include <infin_mul.h>
#include <infin_pow.h>
#include "convert_base.h"

static char *pow_2_n(unsigned int p, char *op_base)
{
	char *res = malloc(sizeof(char) * (p + 2));
	char *result;
	int i = 1;

	res[0] = '1';
	for (i = 1; i < p + 1; i++) {
		res[i] = '0';
	}
	res[i] = '\0';
	result = convert_base(res, "01", op_base, 0);
	free(res);
	return (result);
}

static char *infin_div_wrapped(char *str1, char *str2, char *op_base)
{
	char *quot = "0";
	unsigned int n = 0;
	char *two = "2";
	char *to_sub = infin_add("0", str2, op_base);
	char *res_pow;

	while (compare(to_sub, str1) != 1) {
		to_sub = infin_mul(to_sub, "2", op_base);
		n++;
	}
	while (n != -1) {
		res_pow = pow_2_n(n, op_base);
		to_sub = infin_mul(res_pow, str2, op_base);
		if (compare(to_sub, str1) != 1) {
			quot = infin_add(quot, res_pow, op_base);
			str1 = infin_sub(str1, to_sub, op_base);
		}
		n--;
		free(res_pow);
	}
	return (quot);
}

static char *infin_div_base_case(char *str1, char *str2, char *op_base)
{
	if (compare(str1, str2) == 2)
		return ("0");
	else if (compare(str2, "0") == 0) {
		my_putstr_error("error");
		exit(84);
	}
	else
		return (infin_div_wrapped(str1, str2, op_base));
}

static char *get_pow_of_two(char *str, char *op_base)
{
	char *result = "1";
	int counter = 0;

	while (str[counter]) {
		result = infin_add(result, result, op_base);
		counter++;
	}
	return (result);
}

char *infin_div(char *str1, char *str2, char *op_base)
{
	char *quot;
	int sign = get_sign(str1, str2);

	if (str1[0] == op_base[3])
		str1 = remove_minus(str1);
	if (str2[0] == op_base[3])
		str2 = remove_minus(str2);
	quot = infin_div_base_case(str1, str2, op_base);
	if (sign == 1 && compare(quot, "0") != 0)
		quot = my_dup_without_zero(quot, 1);
	return (quot);
}
