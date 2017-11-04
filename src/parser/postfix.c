/*
** EPITECH PROJECT, 2017
** postfix_new.c
** File description:
** New iteration of postfix
*/

#include <stdlib.h>
#include "utils.h"
#include "stack.h"

static int has_priority(char c1, char c2, char *ope)
{
	if (c2 == ope[0] || c2 == 0)
		return (0);
	if (c1 == ope[2] || c1 == ope[3])
		return (1);
	if (c2 == ope[4] || c2 == ope[5] || c2 == ope[6])
		return (1);
	return (0);
}
	
int priority(char c, char *str, stack_t **stack, char *operands)
{
	if (c == operands[0])
		add_stack(stack, c);
	else {
		if (has_priority(c, (*stack)->data, operands)) {
			put_in_str(out_stack(stack), str);
			priority(c, str, stack, operands);
			return (0);
		}
		else {
			add_stack(stack, c);
			return (0);
		}
	}
	return (0);
}

int unstack(char *str, stack_t **stack, char *operands)
{
	while ((*stack)->data && (*stack)->data != operands[0]) {
		put_in_str(out_stack(stack), str);
	}
	out_stack(stack);
	return (0);
}

int unstack_all(char *str, stack_t **stack)
{
	while ((*stack)->data)
		put_in_str(out_stack(stack), str);
	str[my_strlen(str) - 1] = 0;
	return (0);
}

char *postfix(char *str, char *operands, char *base)
{
	char *to_return = my_alo(str, operands);
	int counter = 0;
	stack_t *stack = create_stack();

	while (str[counter]) {
		if (is_in(str[counter], operands) &&
		    str[counter] != operands[1])
			priority(str[counter], to_return, &stack, operands);
		else if (is_in(str[counter], base))
			get_str_nb(str, to_return, &counter, base);
		else
			unstack(to_return, &stack, operands);
		counter++;
	}
	unstack_all(to_return, &stack);
	free(stack);
	free(str);
	return (to_return);
}
