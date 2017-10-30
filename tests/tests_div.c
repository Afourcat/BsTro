/*
** EPITECH PROJECT, 2017
** tests_div.c
** File description:
** div function test
*/

#include <criterion/criterion.h>
#include <infin_div.h>

Test(infin_div, basic)
{
	cr_assert_str_eq(infin_div("100", "10"), "100",
			 "Should return 1000.\n");
}

Test(infin_div, bigger_than_int)
{
	cr_assert_str_eq(infin_div("2000000000000000000000000", "2")
			 , "1000000000000000000000000",
			 "Should return 1000000000000000000000000.\n");
}

Test(infin_div, inferior_to_zero)
{
	cr_assert_str_eq(infin_div("-123", "-23"), "5",
			 "Should return 5.\n");
}

Test(infin_div, basic_minus)
{
	cr_assert_str_eq(infin_div("-12", "4"), "-3",
			 "Should return -3.\n");
}

Test(infin_div, double_zero)
{
	cr_assert_str_eq(infin_div("0", "1"), "0",
			 "Should return 0.\n");
}

Test(infin_div, zero)
{
	cr_assert_str_eq(infin_div("0", "400"), "0",
			"Should return 0.\n");
}

Test(infin_div, bigger_neg_right)
{
	cr_assert_str_eq(infin_div("2", "-123"), "0",
			"Should return 0.\n");
}

Test(infin_div, bigger_right)
{
	cr_assert_str_eq(infin_div("2", "123"), "0",
			"Should return 0.\n");
}

Test(infin_div, two_one)
{
	cr_assert_str_eq(infin_div("2", "-1"), "-2",
			"Should return -2.\n");
}

Test(infin_div, 14_pow_5)
{
	cr_assert_str_eq(infin_div("38416", "14"), "2744",
			"Should return 2744.\n");
}

Test(infin_div, really_big)
{
	cr_assert_str_eq(infin_div("20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002"
				   , "2"), "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
			"Should return 100*001.\n");
}
