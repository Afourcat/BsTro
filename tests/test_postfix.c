/*
** EPITECH PROJECT, 2017
** tests_postfix.c
** File description:
** Postfix test file
*/

#include <postfix.h>

Test(postfix, basic)
{
	char *test = "1+2";
	
	cr_assert_eq(number(&test), 1234, "Should return 1234.\n" );
	cr_assert_eq(number(&test), &test[3], "Should return &test[3].\n");
}
