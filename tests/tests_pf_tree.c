/*
** EPITECH PROJECT, 2017
** tests_pf_tree.c
** File description:
** Unit tests for the postfixed binary tree
*/

#include <criterion/criterion.h>
#include <pf_tree.h>

Test(pf_tree, create_simple_pf_tree)
{
	char expr[] = "1 3 +";
	char operators[] = "()+-*/%";
	pf_tree_t *tree;

	tree = char_to_ope(expr, operators);
	cr_assert_eq(tree->operator, 2, "It must return 2.\n");
	cr_assert_str_eq(tree->right->number, "3", "It must return 3.\n");
	cr_assert_str_eq(tree->left->number, "1", "It must return 1.\n");
}

Test(pf_tree, create_hard_pf_tree)
{
	char expr[] = "1 220000 7 * 82 4 + 1 - 1 2 - * / -";
	char operators[] = "()+-*/%";
	pf_tree_t *tree;

	tree = char_to_ope(expr, operators);
	cr_assert_eq(tree->operator, 3, "It must return 3.\n"); // -

	cr_assert_eq(tree->right->operator, 5, "It must return 5.\n"); // PREMIER NIVEAU /
	cr_assert_str_eq(tree->left->number, "1", "It must return 1.\n"); // PREMIER NIVEAU 1

	cr_assert_eq(tree->right->left->operator, 4, "It must return 4.\n");
	cr_assert_eq(tree->right->right->operator, 4, "It must return 4.\n");

	cr_assert_str_eq(tree->right->left->left->number, "220000", "It must return 220000.\n");
	cr_assert_str_eq(tree->right->left->right->number, "7", "It must return 7.\n");
	cr_assert_eq(tree->right->right->left->operator, 3, "It must return 3.\n");
	cr_assert_eq(tree->right->right->right->operator, 3, "It must return 3.\n");

	cr_assert_str_eq(tree->right->right->left->right->number, "1", "It must return 1.\n");
	cr_assert_eq(tree->right->right->left->left->operator, 2, "It must return 2.\n");
	cr_assert_str_eq(tree->right->right->right->right->number, "2", "It must return 2.\n");
	cr_assert_str_eq(tree->right->right->right->left->number, "1", "It must return 1.\n");

	cr_assert_str_eq(tree->right->right->left->left->right->number, "4", "It must return 4.\n");
	cr_assert_str_eq(tree->right->right->left->left->left->number, "82", "It must return 82.\n");
}
