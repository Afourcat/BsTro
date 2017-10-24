/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test for add and substract system
*/

#include <add.h>

Test(add, basic)
{
	cr_assert_str_eq(add("4", "2"), "6", "It must return 6.\n");
}

Test(add, bigger_than_int)
{
	cr_assert_str_eq(add("5000000000000000", "2000000000000000"),
			 "7000000000000000" ,
			 "It must return 7000000000000000.\n" );
}

Test(add, double_zero)
{
	cr_assert_str_eq(add("0" , "0"), "0", "It must return 0.\n");
}

Test(add, minus_zero)
{
	cr_assert_str_eq(add("-0" , "-0"), "0", "It must return 0.\n");
}

Test(add, bigger_double_minus)
{
	cr_asser_str_eq(add("-5000000000000000", "-3000000000000000"),
			"-8000000000000000",
			"It must return -8000000000000000.\n");
}


