/*
** EPITECH PROJECT, 2017
** tests_sub.c
** File description:
** Tests for substraction functions
*/

#include <sub.h>

Test(sub, basic)
{
	cr_assert_str_eq(sub("10", "5"), "5", "It must return 5.\n");
}

Test(sub, same_number)
{
	cr_assert_str_eq(sub("1000", "1000"), "0", "It must return 0.\n");
}

Test(sub, second_number_bigger)
{
	cr_assert_str_eq(sub("5", "10"), "-5", "It must return -5.\n");
}

Test(sub, two_zero)
{
	cr_assert_str_eq(sub("0", "0"), "0", "It must return 0.\n");
}

Test(sub, bigger_than_int)
{
	cr_assert_str_eq(sub("2147483649", "1"), "2147483648",
			 "It must return 2147483648.\n");
}
