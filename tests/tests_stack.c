/*
** EPITECH PROJECT, 2017
** stack test
** File description:
** stack test
*/

#include <stack.h>
#include <criterion/criterion.h>

Test(create_stack, basic)
{
	stack_t *stack = create_stack('(');

	cr_assert_eq(stack->data, '(', "Should be '('.\n");
	cr_assert_eq(stack->ptr, NULL, "Should be NULL.\n");
}

Test(add_stack, basic)
{
	stack_t *stack = create_stack('(');
	stack_t *temp = stack;
	
	add_stack(&stack, 'a');
	cr_assert_eq(stack->data, 'a', "Should be 'a'.\n");
	cr_assert_eq(stack->ptr, temp, "Should be temp.\n");
}

Test(out_stack, basic)
{
	stack_t *stack = create_stack('(');
	char data;
	
	add_stack(&stack, 'o');
	data = out_stack(&stack);
	cr_assert_eq(stack->data, '(', "Should be '('.\n");
	cr_assert_eq(data, 'o', "Should be o.\n");
}

Test(size_stack, basic)
{
	stack_t *stack = create_stack('(');
	
	add_stack(&stack, 'o');
	cr_assert_eq(size_stack(stack), 2, "Should be 2.\n");
}

Test(size_stack, longer)
{
	stack_t *stack = create_stack('(');
	
	add_stack(&stack, 'o');
	add_stack(&stack, '6');
	add_stack(&stack, 'T');
	cr_assert_eq(size_stack(stack), 4, "Should be 4.\n");
}


