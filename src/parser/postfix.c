/*
** EPITECH PROJECT, 2017
** postfix
** File description:
** Main functions for the postfix converter
*/

#include <stdlib.h>
#include <stack.h>
#include <postfix.h>
#include <utils.h>

int has_priority(char *ope, char c1, char c2)
{
	if (!is_in(c2, ope))
		return (0);
	if (c1 == ope[0] || c1 == ope[1]) {
		if (c2 == ope[2] || c2 == ope[3] || c2 == ope[4])
			return (0);
		else
			return (1);
	}
	else {
		if (c2 == ope[0] || c2 == ope[1])
			return (0);
		else
			return (1);
	}
}

char *manage_ope(char c, stack_t **stack, char *operands)
{
	char *temp = malloc(sizeof(char));

	if (*stack == 0)
		*stack = create_stack(c);
	else {
		if (has_priority(operands, c, (*stack)->data))
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
	char *str = malloc(sizeof(char) * (size_stack(*stack)) * 2);
	int ctr = 0;

	if (is_in(c, parent) == 1) {
		if (*stack == 0)
			*stack = create_stack(c);
		else
			add_stack(stack, c);
	} else if (is_in(c, parent) == 2) {
		while (*stack && (*stack)->data != parent[0]) {
			str[ctr] = out_stack(stack);
			ctr = ctr + 2;
			str[ctr - 1] = ' ';
		}
		if (*stack)
			out_stack(stack);
	}
	str[my_strlen(str) - 1] = str[my_strlen(str) - 1] == ' ' ? 0 : str[my_strlen(str) - 1]; 
	return (str);
}

char *get_str_nbr(char *str)
{
	char *nb = malloc(sizeof(char) * my_strlen(str));
	int ctr2 = 0;
	int ctr = 0;

	while ((str[ctr] > '9' || str[ctr] < '0') && str[ctr] != '-')
		ctr++;
	if (str[ctr] == '-' &&
	    (str[ctr - 1] < '0' || str[ctr - 1] > '9')) {
		nb[ctr2] = str[ctr];
		ctr2++;
		ctr++;
	}
	while (str[ctr] <= '9' && str[ctr] >= '0') {
		nb[ctr2] = str[ctr];
		ctr++;
		ctr2++;
	}
	return (nb);
}

char *postfix(char *str, char *operands, char *base, char *parent)
{
	char *to_return = malloc(sizeof(char) * my_strlen(str) * 2);
	char *temp;
	stack_t *stack = 0;
	int ctr = 0;

	while (str[ctr]) {
		if (is_in(str[ctr], operands) && (is_in(str[ctr - 1], base)
			|| is_in(str[ctr - 1], &(parent[1]))))
			temp = manage_ope(str[ctr], &stack, operands);
		else if (is_in(str[ctr], parent))
			temp = manage_parent(str[ctr], &stack, parent);
		else
			temp = get_str_nbr(str + ctr);
		ctr = my_strlen(temp) == 0 ? ctr + 1 : ctr + my_strlen(temp);
		my_strcat(to_return, temp);
		if (to_return[my_strlen(to_return) - 1] != ' ')
			my_strcat(to_return, " ");
		free(temp);
	}
	my_strcat(to_return, manage_parent(parent[1], &stack, parent));
	to_return[my_strlen(to_return) - 1] = 0;
	return (to_return);
}
