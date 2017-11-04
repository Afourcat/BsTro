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

char *calc(pf_tree_t *tree, char *nb_base, char neg, int s_nb_base)
{
	if (tree->left == NULL && tree->right == NULL) {
		if (s_nb_base == 10)
			return (tree->number);
//		return (convert_base(tree->number, nb_base, neg, 0));
	}
	return (OPERATORS[tree->operator - 2](
			calc(tree->left, nb_base, neg, s_nb_base),
			calc(tree->right, nb_base, neg, s_nb_base)));
}
