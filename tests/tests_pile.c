/*
** EPITECH PROJECT, 2017
** pile test
** File description:
** pile test
*/

#include <../include/pile.h>
#include <criterion/criterion.h>

Test(create_pile, basic)
{
	pile_t *pile = create_pile('(');

	cr_assert_eq(pile->data, '(', "Should be '('.\n");
	cr_assert_eq(pile->ptr, NULL, "Should be NULL.\n");
}

Test(add_pile, basic)
{
	pile_t *pile = create_pile('(');
	pile_t *temp = pile;
	
	add_pile(&pile, 'a');
	cr_assert_eq(pile->data, 'a', "Should be 'a'.\n");
	cr_assert_eq(pile->ptr, temp, "Should be temp.\n");
}

Test(out_pile, basic)
{
	pile_t *pile = create_pile('(');
	char data;
	
	add_pile(&pile, 'o');
	data = out_pile(&pile);
	cr_assert_eq(pile->data, '(', "Should be '('.\n");
	cr_assert_eq(data, 'o', "Should be o.\n");
}

