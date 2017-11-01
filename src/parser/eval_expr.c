/*
** EPITECH PROJECT, 2017
** eval_expr.c
** File description:
** Core of the program
*/

#include <stdlib.h>
#include "pf_tree.h"
#include "utils.h"
#include "postfix.h"
#include "calc_engine.h"

int find_space(char *neg, char *operands, char *base) // A REFAIRE POUR CHANGER OPERANDS
{
	char c = ' ';

	while (is_in(c, operands) || is_in(c, base)) {
		c++;
	}
	neg[0] = operands[3];
	neg[1] = c;
	return (0);
}

char *eval_expr(char *nb_base, char *op_base, char *expr, int size)
{
	pf_tree_t *pf_tree;
	char* res;

//	expr = my_strdup(expr);
	printf("BEFORE : %s\n", expr);
	expr = parser(expr, op_base);
	printf("PARSER : %s\n", expr);
	expr = parse_neg(expr, nb_base, op_base);
	printf("PARSE_NEG : %s\n", expr);
	expr = postfix(expr, op_base, nb_base);
	printf("POSTFIX : %s\n", expr);
//	expr = my_strdup("0 12 13 15 5 / 6 12 14 30 5 % 10 25 * + % + 46 - / 16 + * 20 - * 43 / 20 * - 0 12 98 42 * - - 16 63 + 50 3 / - * *");
	pf_tree = char_to_pf_tree(expr, op_base);
	res = calc(pf_tree);
	free_pf_tree(pf_tree);
	free(expr);
	return (res);
}
