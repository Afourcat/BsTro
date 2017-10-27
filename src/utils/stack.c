/*
** EPITECH PROJECT, 2017
** stack.c
** File description:
** stack first in first out
*/

#include <stack.h>
#include <stdlib.h>

stack_t *create_stack(void)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	new_stack->data = 0;
	new_stack->ptr = NULL;
	return (new_stack);
}

stack_t *add_stack(stack_t **stack, char data)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	new_stack->data = data;
	new_stack->ptr = *stack;
	*stack = new_stack;
	return (*stack);
}

char out_stack(stack_t **stack)
{
	stack_t *temp = *stack;
	char data = temp->data;

	if ((*stack)->ptr == NULL)
		return (0);
	*stack = temp->ptr;
	free(temp);
	return (data);
}

int size_stack(stack_t *stack)
{
	stack_t *temp = stack;
	int i = 0;
	
	while (temp != NULL) {
		i++;
		temp = temp->ptr;
	}
	return (i);
}
