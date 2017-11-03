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

static char *get_pow_of_two(char *str)
{
	char *result = my_strdup("1");
	int counter = 0;
	char *res = my_strdup(result);
	
	while (str[counter]) {
		result = infin_add(res, result);
		res = my_strdup(result);
		counter++;
	}
	free(res);
	return (result);
}

static char *pow_2_n(unsigned int p)
{
	char *res = malloc(sizeof(char) * (p + 2));
	char *result;
	int i = 1;

	res[0] = '1';
	for (i = 1; i < p + 1; i++) {
		res[i] = '0';
	}
	res[i] = '\0';
	result = get_pow_of_two(res);
	free(res);
	return (result);
}

static char *infin_div_wrapped(char *str1, char *str2)
{
	char *quot = my_strdup("0");
	unsigned int n = 0;
	char *to_sub = my_strdup(str2);
	char *res_pow;

	while (compare(to_sub, str1) != 1) {
		to_sub = infin_mul(to_sub, my_strdup("2"));
		n++;
	}
	free(to_sub);
	n--;
	while (n != -1) {
		res_pow = pow_2_n(n);
		to_sub = infin_mul(my_strdup(res_pow), my_strdup(str2));
		if (compare(to_sub, str1) != 1) {
			quot = infin_add(quot, my_strdup(res_pow));
			str1 = infin_sub(str1, to_sub);
		}
		n--;
		free(res_pow);
		free(to_sub);
	}
	free(str1);
	free(str2);
	return (quot);
}

static char *infin_div_base_case(char *str1, char *str2)
{
	if (compare(str1, str2) == 2)
		return ("0");
	else if (compare(str2, "0") == 0) {
		my_putstr_error("error");
		exit(84);
	}
	else
		return (infin_div_wrapped(str1, str2));
}

char *infin_div(char *str1, char *str2)
{
	char *quot;
	int sign = get_sign(str1, str2);

	if (str1[0] == '-')
		str1 = remove_minus(str1);
	if (str2[0] == '-')
		str2 = remove_minus(str2);
	quot = infin_div_base_case(str1, str2);
	if (sign == 1 && compare(quot, "0") != 0)
		quot = my_dup_without_zero(quot, 1);
	return (quot);
}

int main(int argc, char *argv[])
{
	char *nb1 = my_strdup(argv[1]);
	char *nb2 = my_strdup(argv[2]);
	char *res = infin_div(nb1, nb2);
	my_putstr(res);
	free(res);
	return 0;
}
