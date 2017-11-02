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

static char *infin_div_wrapped(char *str1, char *str2)
{
	char *quot = "0";
	char *n = "0";
	char *two = "2";
	char *to_sub = infin_add("0", str2);

	while (compare(to_sub, str1) != 1) {
		to_sub = infin_mul(to_sub, "2");
		n = infin_add(n, "1");
	}
	while (n[0] != '-') {
		to_sub = infin_mul(infin_pow(two, n), str2);
		if (compare(to_sub, str1) != 1) {
			quot = infin_add(quot, infin_pow(two, n));
			str1 = infin_sub(str1, to_sub);
		}
		n = infin_sub(n, "1");
	}
	return(quot);
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

static char *get_pow_of_two(char *str)
{
	char *result = "1";
	int counter = 0;
	
	while (str[counter]) {
			result = infin_add(result, result); 
			counter++;
	}
	return (result);
}

/**
 * \fn char *infin_div (char *str1, char *str2)
 * \brief Function that divides two string numbers and returns the quotient.
 * \param str1 The dividend of the division
 * \param str2 The divisor of the division
 * \return The quotient as a string number.
 */
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
