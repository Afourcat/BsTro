/*
** EPITECH PROJECT, 2017
** infin_div.c
** File description:
** infinite multiplication functions
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_sub.h>
#include <infin_add.h>
#include <infin_mul.h>
#include <infin_pow.h>

static char *infin_div_wrapped(char *str1, char *str2)
{
	char *quot = "0";
	char *n = "0";
	char *empowered = infin_pow("2", n);
	char *to_sub = infin_mul(empowered, str2);
	
	while (compare(to_sub, str1) != 1) {
		to_sub = infin_mul(to_sub, 2);
		n = infin_add(n, "1");
	}
	infin_sub(n, "1");
	while (compare(n, 0) == 1){
		empowered = infin_pow("2", n);
		to_sub = infin_mul(empowered, str2);
		if (compare(to_sub, str1) != 1) {
			quot = infin_add(quot, empowered);
			str1 = infin_sub(str1, to_sub);
		}
		infin_sub(n, "1");
	}
	return(quot);
}

char *infin_div(char *str1, char *str2)
{
	char *quot;
	int sign = get_sign(str1, str2);

	if (str1[0] == '-')
		str1 = get_oposed_number(str1);
	if (str2[0] == '-')
		str2 = get_oposed_number(str2);
	quot = infin_div_wrapped(str1, str2);
	if (sign == 1)
		quot = get_oposed_number(quot);
	return (quot);
}
