/*
** EPITECH PROJECT, 2017
** tests_parser.c
** File description:
** parser test file
*/

#include <parser.h>

Test(number, basic)
{
	char *test = "1234salut";

	cr_assert_eq(number(&test), 1234, "Should return 1234.\n" );
	cr_assert_eq(number(&test), &test[3], "Should return &test[3].\n");
}
