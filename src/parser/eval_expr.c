/*
** EPITECH PROJECT, 2017
** eval_expr.c
** File description:
** Core of the program
*/

#include <stdlib.h>
#include "pf_tree.h"
#include "utils.h"
#include "error.h"
#include "postfix.h"
#include "calc_engine.h"
#include "convert_base.h"

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
	int s_nb_base = my_strlen(nb_base);
	
	my_putchar('A');
	check_syntax(expr, op_base, nb_base);
	my_putchar('A');
	find_space(spaces, op_base, nb_base);
	my_putchar('A');
	replace_char_to(expr, spaces[0], spaces[1]);
	my_putchar('A');
	expr = parser(expr, op_base);
	my_putchar('A');
	expr = parse_neg(expr, nb_base, op_base);
	my_putchar('A');
	expr = postfix(expr, op_base, nb_base);
	my_putchar('A');
	pf_tree = char_to_pf_tree(expr, op_base);
	my_putchar('A');
	expr = calc(pf_tree, nb_base, op_base[3], s_nb_base);
	my_putchar('A');
	if (s_nb_base != 10)
//		expr = convert_base(expr, nb_base, op_base[3], 1);
	my_putchar('A');
	free_pf_tree(pf_tree);
	my_putchar('A');
	replace_char_to(expr, spaces[1], spaces[0]);	
	my_putchar('A');
	free(spaces);
//	free(op_base);
//	free(nb_base);
	return (expr);
}
