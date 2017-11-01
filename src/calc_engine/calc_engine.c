/*
** EPITECH PROJECT, 2017
** calc_engine.c
** File description:
** Functions that execute the calcul
*/

#include <stdlib.h>
#include "pf_tree.h"
#include "calc.h"

/**
 * \fn char *calc (pf_tree_t *tree)
 * \brief Function that compute each node of the binary tree passed as
 * parameter, using pointers on wrappers for operations.
 * \param tree The binary tree node to be computed.
 * \return The value of the computation of the two last nodes or
 * the value of the node.
 */
char *calc(pf_tree_t *tree, char *nb_base, char neg)
{
	if (tree->left == NULL && tree->right == NULL) {
		return (convert_base(tree->number, nb_base, neg, 0));
	}
	return (OPERATORS[tree->operator - 2]
		(calc(tree->left, nb_base, neg),
		 calc(tree->right, nb_base, neg)));
}
