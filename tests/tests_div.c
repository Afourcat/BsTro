/*
** EPITECH PROJECT, 2017
** tests_div.c
** File description:
** div function test
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "infin_div.h"

Test(infin_div, basic)
{
	cr_assert_str_eq(infin_div(my_strdup("100"), my_strdup("10")), "10",
			 "Should return 10.\n");
}

Test(infin_div, bigger_than_int)
{
	cr_assert_str_eq(infin_div(my_strdup("2000000000000000000000000"), my_strdup("2"))
			 , "1000000000000000000000000",
			 "Should return 1000000000000000000000000.\n");
}

Test(infin_div, inferior_to_zero)
{
	cr_assert_str_eq(infin_div(my_strdup("-123"), my_strdup("-23")), "5",
			 "Should return 5.\n");
}

Test(infin_div, basic_minus)
{
	cr_assert_str_eq(infin_div(my_strdup("-12"), my_strdup("4")), "-3",
			 "Should return -3.\n");
}

Test(infin_div, double_zero)
{
	cr_assert_str_eq(infin_div(my_strdup("0"), my_strdup("1")), "0",
			 "Should return 0.\n");
}

Test(infin_div, zero)
{
	cr_assert_str_eq(infin_div(my_strdup("0"), my_strdup("400")), "0",
			"Should return 0.\n");
}

Test(infin_div, bigger_neg_right)
{
	cr_assert_str_eq(infin_div(my_strdup("2"), my_strdup("-123")), "0",
			"Should return 0.\n");
}

Test(infin_div, bigger_right)
{
	cr_assert_str_eq(infin_div(my_strdup("2"), my_strdup("123")), "0",
			"Should return 0.\n");
}

Test(infin_div, two_one)
{
	cr_assert_str_eq(infin_div(my_strdup("2"), my_strdup("-1")), "-2",
			"Should return -2.\n");
}

Test(infin_div, 14_pow_5)
{
	cr_assert_str_eq(infin_div(my_strdup("38416"), my_strdup("14")), "2744",
			"Should return 2744.\n");
}

Test(infin_div, really_big)
{
	cr_assert_str_eq(infin_div(my_strdup("20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002")
				   , my_strdup("2")), "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
			"Should return 100*001.\n");
}
