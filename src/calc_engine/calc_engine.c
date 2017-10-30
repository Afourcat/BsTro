/*
** EPITECH PROJECT, 2017
** calc_engine.c
** File description:
** Functions that execute the calcul
*/

#include "pf_tree.h"
#include "calc.h"

char *calc(pf_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL) {
		return (tree->number);
	}
	return (OPERATORS[tree->operator - 2]
		(calc(tree->left), calc(tree->right)));
}
