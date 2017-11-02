/*
** EPITECH PROJECT, 2017
** calc_engine.c
** File description:
** Functions that execute the calcul
*/

#include <stdlib.h>
#include "pf_tree.h"
#include "convert_base.h"
#include "calc.h"

char *calc(pf_tree_t *tree, char *nb_base, char *op_base)
{
	if (tree->left == NULL && tree->right == NULL) {
		return (convert_base(tree->number, nb_base, op_base[3], 0));
	}
	return (OPERATORS[tree->operator - 2](
			calc(tree->left, nb_base, op_base),
			calc(tree->right, nb_base, op_base), op_base));
}
