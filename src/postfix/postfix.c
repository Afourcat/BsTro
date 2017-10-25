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
	else {
		if (is_in(c, operands) <= is_in((*stack)->data, operands))
			temp[0] = out_stack(stack);
		else
			temp[0] = 0;
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
		while (*stack && (*stack)->data != parent[0]) {
			str[counter] = out_stack(stack);
			counter = counter + 2;
			str[counter - 1] = ' ';
		}
		if (*stack)
			out_stack(stack);
	}
	return (str);
}

char *get_str_nbr(char *str)
{
	char *nb = malloc(sizeof(char) * my_strlen(str));
	int counter2 = 0;
	int counter = 0;

	while ((str[counter] > '9' || str[counter] < '0') && str[counter] != '-')
		counter++;
	if (str[counter] == '-' &&
	    (str[counter - 1] < '0' || str[counter - 1] > '9')) {
		nb[counter2] = str[counter];
		counter2++;
		counter++;
	}
	while (str[counter] <= '9' && str[counter] >= '0') {
		nb[counter2] = str[counter];
		counter++;
		counter2++;
	}
	return (nb);
}

char *postfix(char *str, char *operands, char *base, char *parent)
{
	char *to_return = malloc(sizeof(char) * my_strlen(str) * 2);
	stack_t *stack = 0;
	int counter = 0;

	while (str[counter]) {
		if (is_in(str[counter], operands)
		    && (is_in(str[counter - 1], base)
			|| is_in(str[counter - 1], &(parent[1]))))
			my_strcat(to_return, manage_ope(str[counter], &stack, operands));
		else if (is_in(str[counter], parent))
			my_strcat(to_return, manage_parent(str[counter], &stack, parent));
		else {
			my_strcat(to_return, get_str_nbr(str + counter));
			if (is_in(str[counter], operands))
				counter++;
		}
		if (to_return[my_strlen(to_return) - 1] != ' ')
			my_strcat(to_return, " ");
		counter++;
	}
	my_strcat(to_return, manage_parent(parent[1], &stack, parent));
	return (to_return);
}
