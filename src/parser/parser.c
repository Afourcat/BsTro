/*
** EPITECH PROJECT, 2017
** parser.c
** File description:
** parser for the eval_expr function
*/

#include "utils.h"

char set_sign(char *expr,char *op_base, int *shift, int i)
{
	int sign = 1;

	while (expr[i + (*shift)] == op_base[3] ||
	       expr[i + (*shift)] == op_base[2]) {
		sign = (expr[i + (*shift)++] == op_base[3]) ? - sign : sign;
	}
	if (i - 1 >= 0 && !is_in(expr[i - 1], op_base + 2))
		expr[i] = (sign == -1) ? op_base[3] : op_base[2];	
	else
		expr[i] = (sign == -1) ? op_base[3] : expr[i + (*shift)++];
}

char *parse_sign(char *expr, char *op_base, int *i, int shift)
{
	int size = my_strlen(expr);
	while ((*i) + shift <= size) {
		if (expr[(*i) + shift] == op_base[2] ||
		    expr[(*i) + shift] == op_base[3]) {
			set_sign(expr, op_base, &shift, (*i));
			shift--;
		} else
			expr[(*i)] = expr[(*i) + shift];
		(*i)++;
	}
}

char *parser(char *expr, char *op_base)
{
	int i = 0;
	int shift = 0;

	parse_sign(expr, op_base, &i, shift);
	parse_neg(expr, op_base);
	expr[i] = 0;
	return (expr);
}
