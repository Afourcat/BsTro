/*
** EPITECH PROJECT, 2017
** stack test
** File description:
** stack test
*/

#include <../include/stack_void.h>
#include <criterion/criterion.h>

Test(create_stack_v, basic)
{
	stack_v_t *stack_v = create_stack_v();

	cr_assert_eq(stack_v->data, NULL, "Should be '('.\n");
	cr_assert_eq(stack_v->ptr, NULL, "Should be NULL.\n");
}

Test(create_stack_v, nothing_to_remove)
{
	stack_v_t *stack_v = create_stack_v();
	char *data;
	
	data = (char *) out_stack_v(&stack_v);
	cr_assert_eq(stack_v->data, NULL, "Should be NULL.\n");
	cr_assert_eq(data, NULL, "Should be NULL.\n");
	cr_assert_eq(stack_v->ptr, NULL, "Should be NULL.\n");
}


Test(add_stack_v, basic)
{
	stack_v_t *stack_v = create_stack_v();
	stack_v_t *temp = stack_v;
	
	add_stack_v(&stack_v,(void *) "a");
	cr_assert_eq(*((char *) stack_v->data), 'a', "Should be 'a'.\n");
	cr_assert_eq(stack_v->ptr, temp, "Should be temp.\n");
}

Test(out_stack_v, allo)
{
	stack_v_t *stack_v = create_stack_v();
	char *data;
	
	add_stack_v(&stack_v,(void *) "o");
	data = (char *) out_stack_v(&stack_v);
	cr_assert_eq(stack_v->data, NULL, "Should be NULL.\n");
	cr_assert_eq(data[0], 'o', "Should be o.\n");
}

Test(size_stack_v, basic)
{
	stack_v_t *stack_v = create_stack_v();
	
	add_stack_v(&stack_v,(void *) 'o');
	cr_assert_eq(size_stack_v(stack_v), 2, "Should be 2.\n");
}

Test(size_stack_v, longer)
{
	stack_v_t *stack_v = create_stack_v();
	
	add_stack_v(&stack_v,(void *) 'o');
	add_stack_v(&stack_v,(void *) '6');
	add_stack_v(&stack_v,(void *) 'T');
	cr_assert_eq(size_stack_v(stack_v), 4, "Should be 4.\n");
}


