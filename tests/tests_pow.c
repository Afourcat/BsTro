/*
** EPITECH PROJECT, 2017
** tests_pow.c
** File description:
** pow test
*/

#include <criterion/criterion.h>
#include <infin_pow.h>

Test(infin_pow, basic)
{
	cr_assert_str_eq(infin_pow("14", "4"), "38416", "Should return 38416.\n");
}

Test(infin_pow, by_one)
{
	cr_assert_str_eq(infin_pow("1883", "1"), "1883", "Should return 1883.\n");
}

Test(infin_pow, bigger_one)
{
	cr_assert_str_eq(infin_pow("45", "6"), "8303765625", "Should return 8303765625.\n");
}
