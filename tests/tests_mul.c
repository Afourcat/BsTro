/*
** EPITECH PROJECT, 2017
** tests_mul.c
** File description:
** mul function test
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "infin_mul.h"

Test(infin_mul, basic)
{
	cr_assert_str_eq(infin_mul(my_strdup("100"), my_strdup("10")), "1000",
			 "Should return 1000.\n");
}

Test(infin_mul, bigger_than_int)
{
	cr_assert_str_eq(infin_mul(my_strdup("2000000000000000000000000"), my_strdup("2"))
			 , "4000000000000000000000000",
			 "Should return 4000000000000000000000000.\n");
}

Test(infin_mul, inferior_to_zero)
{
	cr_assert_str_eq(infin_mul(my_strdup("-123"), my_strdup("-23")), "2829",
			 "Should return 2829.\n");
}

Test(infin_mul, basic_minus)
{
	cr_assert_str_eq(infin_mul(my_strdup("-11"), my_strdup("4")), "-44",
			 "Should return -44.\n");
}

Test(infin_mul, double_zero)
{
	cr_assert_str_eq(infin_mul(my_strdup("0"), my_strdup("0")), "0",
			 "Should return 0.\n");
}

Test(infin_mul, zero)
{
	cr_assert_str_eq(infin_mul(my_strdup("0"), my_strdup("400")), "0",
			"Should return 0.\n");
}

Test(infin_mul, bigger_neg_right)
{
	cr_assert_str_eq(infin_mul(my_strdup("2"), my_strdup("-123")), "-246",
			"Should return -246.\n");
}

Test(infin_mul, bigger_right)
{
	cr_assert_str_eq(infin_mul(my_strdup("2"), my_strdup("123")), "246",
			"Should return 246.\n");
}

Test(infin_mul, two_one)
{
	cr_assert_str_eq(infin_mul(my_strdup("2"), my_strdup("-1")), "-2",
			"Should return -2.\n");
}

Test(infin_mul, 14_pow_5)
{
	cr_assert_str_eq(infin_mul(my_strdup("38416"), my_strdup("14")), "537824",
			"Should return 537824.\n");
}

Test(infin_mul, really_big)
{
	cr_assert_str_eq(infin_mul(my_strdup("20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002")
				   , my_strdup("2")), "40000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004",
			"Should return 400*004.\n");
}
