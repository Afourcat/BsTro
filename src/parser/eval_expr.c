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

static int find_space(char *spaces, char *op_base, char *nb_base)
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

static char *parse_and_calc(char *expr, char *nb_base, char *op_base)
{
	pf_tree_t *pf_tree;
	int s_nb_base = my_strlen(nb_base);
	
	expr = parser(expr, op_base);
	expr = parse_neg(expr, nb_base, op_base);
	expr = postfix(expr, op_base, nb_base);
	pf_tree = char_to_pf_tree(expr, op_base);
	expr = calc(pf_tree, nb_base, op_base[3], s_nb_base);
	if (s_nb_base != 10)
		expr = convert_base(expr, nb_base, op_base[3], 1);
	free_pf_tree(pf_tree);
	return (expr);
}

char *eval_expr(char *nb_base, char *op_base, char *expr, int size)
{
	char *tmp_nb_base;
	int base_10 = compare_base_10(nb_base);
	char* spaces = my_calloc(sizeof(char) * 3);
	
	check_syntax(expr, op_base, nb_base);	
	if (base_10 == 0) {
		replace(expr, nb_base, "0123456789");
		tmp_nb_base = my_strdup(nb_base);
		nb_base = "0123456789";
	}
	find_space(spaces, op_base, nb_base);
	replace_char_to(expr, spaces[0], spaces[1]);
	expr = parse_and_calc(expr, nb_base, op_base);
	if (base_10 == 0) {
		replace(expr, nb_base, tmp_nb_base);
		free(tmp_nb_base);
	}
	replace_char_to(expr, spaces[1], spaces[0]);	
	free(spaces);
	return (expr);
}
