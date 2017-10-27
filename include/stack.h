/*
** EPITECH PROJECT, 2017
** stack.h
** File description:
** Header for the char stack structure
*/

#ifndef STACK_H_
#define STACK_H_

typedef struct stack
{
	char data;
	struct stack *ptr;
} stack_t;

stack_t *create_stack(void);
stack_t *add_stack(stack_t **pile, char data);
char out_stack(stack_t **pile);
int size_stack(stack_t *pile);

#endif /* STACK_H_ */
