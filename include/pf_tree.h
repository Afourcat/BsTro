/*
** EPITECH PROJECT, 2017
** pf_tree.h
** File description:
** Structure for the binary tree
*/

#ifndef PF_TREE_H_
#define PF_TREE_H_

const int OP_PLUS_IDX = 2;
const int OP_SUB_IDX = 3;
const int OP_NEG_IDX = 3;
const int OP_MUL_IDX = 4;
const int OP_DIV_IDX = 5;
const int OP_MOD_IDX = 6;

typedef struct pf_tree {
	int operator;
	char *number;
	struct ope *left;
	struct ope *right;
} pf_tree_t;

#endif /* PF_TREE_H_ */


