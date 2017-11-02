/*
** EPITECH PROJECT, 2017
** stack.c
** File description:
** stack first in first out
*/

#include <stdlib.h>
#include "stack_void.h"

stack_v_t *create_stack_v(void)
{
	stack_v_t *new_stack_v = malloc(sizeof(stack_v_t));

	new_stack_v->data = NULL;
	new_stack_v->ptr = NULL;
	return (new_stack_v);
}

stack_v_t *add_stack_v(stack_v_t **stack_v, void *data)
{
	stack_v_t *new_stack_v = malloc(sizeof(stack_v_t));

	new_stack_v->data = data;
	new_stack_v->ptr = *stack_v;
	*stack_v = new_stack_v;
	return (*stack_v);
}

void *out_stack_v(stack_v_t **stack_v)
{
	stack_v_t *temp = *stack_v;
	void *data;

	if (temp->data == NULL) {
		return (NULL);
	}
	data = temp->data;
	*stack_v = (*stack_v)->ptr;
	free(temp);
	return (data);
}

int size_stack_v(stack_v_t *stack_v)
{
	stack_v_t *temp = stack_v;
	int i = 0;

	while (temp != NULL) {
		i++;
		temp = temp->ptr;
	}
	return (i);
}
