/*
** EPITECH PROJECT, 2017
** parser.c
** File description:
** Parse the char before sending it to postfix
*/

#include <stdlib.h>
#include <unistd.h>
#include <utils.h>

static int set_sign(char *str, int i, int *shift, char *op_base)
{
	int sign = 1;

	while (str[i + *shift] == op_base[3] ||
	       str[i + *shift] == op_base[2]) {
		sign = (str[i + *shift] == op_base[3]) ? - sign : 1;
		(*shift)++;
	}
	if (is_in(str[i - 1], op_base + 2))
		str[i] = (sign == -1) ? op_base[3] : str[i + (*shift)++];
	else
		str[i] = (sign == -1) ? op_base[3] : op_base[2];
}

static void parse_sign(char *str, char *op_base, int *i, int shift)
{
	int size = my_strlen(str);

	while (++(*i) + shift <= size)
		if (str[(*i) + shift] == op_base[2] ||
		    str[(*i) + shift] == op_base[3]) {
			set_sign(str, (*i), &shift, op_base);
			shift--;
		} else
			str[(*i)] = str[(*i) + shift];
}

char *parser(char *str, char *op_base)
{
	int i = 0;
	int shift = 0;
	int sign = 1;

	if (str[i] == op_base[2] || str[i] == op_base[3]) {
		shift++;
		sign = (str[i] == op_base[3]) ? - sign : 1;
		while (str[i + shift] == op_base[3] ||
		       str[i + shift] == op_base[2])
			sign = (str[i + shift++] == op_base[3]) ? - sign : sign;
		if (sign == -1) {
			str[i] = op_base[3];
			shift--;
		} else
			str[i] = str[i + shift];
	}
	parse_sign(str, op_base, &i, shift);
	str[i] = 0;
	return (str);
}
