/*
** EPITECH PROJECT, 2017
** pf_tree.h
** File description:
** Header for the binary tree structure
*/

#ifndef PF_TREE_H_
#define PF_TREE_H_

typedef struct pf_tree {
	int operator;
	char *number;
	struct pf_tree *left;
	struct pf_tree *right;
} pf_tree_t;

int get_operator(char *str, char *base);
char *get_number(char *str);
pf_tree_t *create_ope(char *str, char *base);
pf_tree_t *char_to_ope(char *str, char *base);

#endif /* PF_TREE_H_ */
