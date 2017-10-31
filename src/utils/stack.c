/*
** EPITECH PROJECT, 2017
** stack.c
** File description:
** stack first in first out
*/

#include <stdlib.h>
#include "stack.h"

/**
 * \fn stack_t* create_stack (void)
 * \brief Create stack_t.
 * \return Pointer on the newly created stack.
 */
stack_t *create_stack(void)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	new_stack->data = 0;
	new_stack->ptr = NULL;
	return (new_stack);
}

/**
 * \fn stack_t add_stack (stack_t **stack, char data)
 * \brief Add an element on the stack specified as parameter.
 * \param stack The address of the pointer on the first element of the stack.
 * \param data The data to add to the stack.
 * \return The pointer on the new element of the stack.
 */
stack_t *add_stack(stack_t **stack, char data)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	new_stack->data = data;
	new_stack->ptr = *stack;
	*stack = new_stack;
	return (*stack);
}

/**
 * \fn char out_stack (stack_t **stack)
 * \brief Unstack the first element of the stack
 * \param stack The address of the pointer on the first element of the stack.
 * \return The first element of the stack.
 */
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

/**
 * \fn int size_stack (stack_t *stack)
 * \brief Compute the size of the stack passed as argument.
 * \param stack The first element of the stack.
 * \return The size of the stack.
 */
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
