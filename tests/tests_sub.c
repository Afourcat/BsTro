/*
** EPITECH PROJECT, 2017
** tests_sub.c
** File description:
** Tests for substraction functions
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "infin_add.h"
#include "infin_sub.h"

Test(infin_sub, basic)
{
	cr_assert_str_eq(infin_sub(my_strdup("10"), my_strdup("5")), "5", "It must return 5.\n");
}

Test(infin_sub, same_number)
{
	cr_assert_str_eq(infin_sub(my_strdup("1000"), my_strdup("1000")), "0", "It must return 0.\n");
}

Test(infin_sub, second_number_bigger)
{
	cr_assert_str_eq(infin_sub(my_strdup("5"), my_strdup("10")), "-5", "It must return -5.\n");
}

Test(infin_sub, two_zero)
{
	cr_assert_str_eq(infin_sub(my_strdup("0"), my_strdup("0")), "0", "It must return 0.\n");
}

Test(infin_sub, bigger_than_int)
{
	cr_assert_str_eq(infin_sub(my_strdup("2147483649"), my_strdup("1")), "2147483648",
			 "It must return 2147483648.\n");
}

Test(infin_sub, bigger_than_int2)
{
	cr_assert_str_eq(infin_sub(my_strdup("5000000000000000000000000"),
			     my_strdup("1000000000000000000000000")),
			 "4000000000000000000000000",
			 "It must return 4000000000000000000000000.\n");
}

Test(infin_add, minus_zero)
{
	cr_assert_str_eq(infin_add(my_strdup("-0") , my_strdup("-0")), "0", "It must return 0.\n");
}

Test(infin_add, zero)
{
	cr_assert_str_eq(infin_add(my_strdup("-0") , my_strdup("-0")), "0", "It must return 0.\n");
}

Test(infin_add, zero_1)
{
	cr_assert_str_eq(infin_add(my_strdup("-0") , my_strdup("-0")), "0", "It must return 0.\n");
}

Test(infin_add, zero_2)
{
	cr_assert_str_eq(infin_add(my_strdup("-0") , my_strdup("-0")), "0", "It must return 0.\n");
}

Test(infin_add, bigger_double_mi)
{
	cr_assert_str_eq(infin_add(my_strdup("5000000000000000"), my_strdup("3000000000000000")),
			"8000000000000000",
			"It must return 8000000000000000.\n");
}
