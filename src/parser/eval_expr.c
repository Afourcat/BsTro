/*
1;2802;0c** EPITECH PROJECT, 2017
** eval_expr.c
** File description:
** Core of the program
*/

#include <stdlib.h>
#include "pf_tree.h"
#include "utils.h"
#include "postfix.h"
#include "calc_engine.h"

int find_space(char *spaces, char *op_base, char *nb_base)
{
	char c = ' ';
	int i = 0;
	
	while (is_in(c, op_base) || is_in(c, nb_base))
		c++;
	while (is_in(' ', op_base + i) || is_in(' ', nb_base + i))
		i++;
	i--;
	if (is_in(' ', op_base)) {
		spaces[0] = op_base[i];
		op_base[i] = c;
	} else if (is_in(' ', nb_base)) {
		spaces[0] = nb_base[i];
		nb_base[i] = c;
	} else
		spaces[0] = c;
	spaces[1] = c;
        
	return (0);
}


void replace_char_to(char *str, char in, char out)
{
	int size = my_strlen(str);
	for (int i = 0; i < size; i++)
		if (str[i] == out)
			str[i] = in;
}

char *eval_expr(char *nb_base, char *op_base, char *expr, int size)
{
	pf_tree_t *pf_tree;
	char* spaces = my_calloc(3);

	//find_space(spaces, op_base, nb_base);
	replace_char_to(expr, spaces[0], spaces[1]);
	printf("BEFORE : %s|\n", expr);
	expr = parser(expr, op_base);
	printf("PARSER : %s|\n", expr);
	expr = parse_neg(expr, nb_base, op_base);
	printf("PARSE_NEG : %s|\n", expr);
	expr = postfix(expr, op_base, nb_base);
	printf("POSTFIX : %s|\n", expr);
//	expr = my_strdup("0 12 13 15 5 / 6 12 14 30 5 % 10 25 * + % + 46 - / 16 + * 20 - * 43 / 20 * - 0 12 98 42 * - - 16 63 + 50 3 / - * *");
	pf_tree = char_to_pf_tree(expr, op_base);
	printf("APRES ARBRE : %s|\n", expr);
	expr = calc(pf_tree, nb_base, op_base[3]);
	printf("CALC : %s|\n", expr);
	expr = convert_base(expr, nb_base, op_base[3], 1);
	printf("CONVERT : %s\n", expr);
	free_pf_tree(pf_tree);
//	free(expr);
//	free(spaces);
	replace_char_to(expr, spaces[1], spaces[0]);
	printf("REPLACED : %s\n", expr);
	return (expr);
}
