/*
** EPITECH PROJECT, 2017
** postfix
** File description:
** Main functions for the postfix converter
*/

#include <stdlib.h>
#include "../../include/stack.h"
#include "../../include/utils.h"

int is_in(char c, char *str)
{
	int counter = 0;

	while (str[counter]) {
		if (c == str[counter])
			return (counter + 1);
		counter++;
	}
	return (0);
}

char *manage_ope(char c, stack_t **stack, char *operands)
{
	char *temp = malloc(sizeof(char));
	
	if (*stack == 0)
		*stack = create_stack(c);
	else if (is_in(c, operands) <= is_in((*stack)->data, operands)) {
	        temp[0] = out_stack(stack);
		if (*stack == 0)
			*stack = create_stack(c);
		else
			add_stack(stack, c);
	}
	return (temp);
}

char *manage_parent(char c, stack_t **stack, char *parent)
{
	char *str = malloc(sizeof(char) * size_stack(*stack));
	int counter = 0;
	
	if (is_in(c, parent) == 1) {
		if (*stack == 0)
			*stack = create_stack(c);
		else
			add_stack(stack, c);
	} else if (is_in(c, parent) == 2) {
		while ((*stack)->data != parent[0]) {
			str[counter] = out_stack(stack);
			counter++;
		}
		out_stack(stack);
	}
	return (str);
}

char *get_str_nbr(char *str)
{
	char *nb = malloc(sizeof(char) * my_strlen(str));
	int counter2 = 0;
	int counter = -1;

	while (str[counter + 1] > '9' || str[counter + 1] < '0')
		counter++;
	if (str[counter] == '-') {
		nb[counter2] = str[counter];
		counter2++;
	}
	counter++;
	while (str[counter] <= '9' && str[counter] >= '0') {
		nb[counter2] = str[counter];
		counter++;
		counter2++;
	}
	return (nb);
}

char *postfix(char *str, char *operands, char *base, char *parent)
{
	char *to_return = malloc(sizeof(char) * my_strlen(str));
	stack_t *stack = 0;
	int counter = 0;

	while (str[counter]) {
		if (is_in(str[counter], operands)
		    && !is_in(str[counter], base))
			my_strcat(to_return, manage_ope(str[counter], &stack, operands));
		else if (is_in(str[counter], parent))
			my_strcat(to_return, manage_parent(str[counter], &stack, parent));
		else
			my_strcat(to_return, get_str_nbr(str + counter));
		my_strcat(to_return, " ");
		counter++;
	}
	return (to_return);
}