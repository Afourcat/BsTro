/*
** EPITECH PROJECT, 2017
** stack.h
** File description:
** Header for the void stack structure
*/

#ifndef STACK_VOID_H_
#define STACK_VOID_H_

typedef struct stack_v
{
	void *data;
	struct stack_v *ptr;
} stack_v_t;

stack_v_t *create_stack_v(void);
stack_v_t *add_stack_v(stack_v_t **stack_v, void *data);
void *out_stack_v(stack_v_t **stack_v);
int size_stack_v(stack_v_t *stack_v);

#endif /* STACK_VOID_H_ */
