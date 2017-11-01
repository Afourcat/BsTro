/*
** EPITECH PROJECT, 2017
** pf_tree.c
** File description:
** Binary tree for postfixed expression
*/

#include <stdlib.h>
#include <pf_tree.h>
#include <stack_void.h>
#include <utils.h>

int get_tree_operator(char *str, char *base)
{
	int i = 0;

	if (str[1] != ' ' && str[1] != '\0') {
		return (-1);
	}
	while (base[i]) {
		if (str[0] == base[i]) {
			return (i);
		}
		i++;
	}
	return (-1);
}

char *get_tree_number(char *str)
{
	int size = my_strlen(str);
	int i = 0;
	char *s;

	while (i < size && str[i] != ' ') {
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	for (int j = 0; j < i; j++) {
		s[j] = str[j];
	}
	s[i] = 0;
	return (s);
}

pf_tree_t *create_pf_tree(char *str, char *base)
{
	pf_tree_t *ope = malloc(sizeof(pf_tree_t));
	int operator = get_tree_operator(str, base);

	if (ope == NULL)
		return (NULL);
	if (operator == -1) {
		ope->operator = -1;
		ope->number = get_tree_number(str);
	} else {
		ope->operator = operator;
		ope->number = NULL;
	}
	ope->left = NULL;
	ope->right = NULL;
	return (ope);
}

pf_tree_t *char_to_pf_tree(char *str, char *base)
{
	stack_v_t *stack = create_stack_v();
	int i = 0;
	int operator;
	pf_tree_t *tmp;
	int size = my_strlen(str);

	while (str[i] != '\0' && i < size) {
		tmp = create_pf_tree(str + i, base);
		if (tmp->operator != -1) {
			tmp->right = out_stack_v(&stack);
			tmp->left = out_stack_v(&stack);
		} else
			i += my_strlen(tmp->number) - 1;
		add_stack_v(&stack, tmp);
		i += 2;
	}
	return (out_stack_v(&stack));
}

void free_pf_tree(pf_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL) {
		free(tree);
	} else {
		free_pf_tree(tree->left);
		free_pf_tree(tree->right);
		free(tree);
	}
}
