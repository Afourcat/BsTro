/*
** EPITECH PROJECT, 2017
** stack.c
** File description:
** stack first in first out
*/

#include <stdlib.h>
#include "stack_void.h"

/**
 * \fn stack_v_t *create_stack_v (void)
 * \brief Function that create a void stack.
 * \return The pointer on the newly created void stack.
 */
stack_v_t *create_stack_v(void)
{
	stack_v_t *new_stack_v = malloc(sizeof(stack_v_t));

	new_stack_v->data = NULL;
	new_stack_v->ptr = NULL;
	return (new_stack_v);
}

/**
 * \fn stack_v_t *add_stack_v (stack_v_t **stack_v, void *data)
 * \brief Function that add the data on top of the given void stack.
 * \param stack_v The address of the pointer on the top of the void stack.
 * \param data The data to be added on the top of the void stack.
 * \return The address of the top element of the void stack.
 */
stack_v_t *add_stack_v(stack_v_t **stack_v, void *data)
{
	stack_v_t *new_stack_v = malloc(sizeof(stack_v_t));

	new_stack_v->data = data;
	new_stack_v->ptr = *stack_v;
	*stack_v = new_stack_v;
	return (*stack_v);
}

/**
 * \fn void *out_stack_v (stack_v_t **stack_v)
 * \brief Function that unstacks the top element of the stack.
 * \param stack_v The address of the pointer on the top of the void stack.
 * \return he data retrieved from the top of the void stack.
 */
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

/**
 * \fn int size_stack_v (stack_v_t *stack_v)
 * \brief Function that compute the size of the void stack and returns it.
 * \param stack_v The address of the top element of the void stack.
 * \return The size of the void stack.
 */
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
