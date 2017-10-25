/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test for add and substract system
*/

#include <infin_add.h>
#include <criterion/criterion.h>

Test(inf_add, basic)
{
	cr_assert_str_eq(inf_add("2", "4"), "6", "It must return 6.\n");
}

Test(inf_add, bigger_than_int)
{
	cr_assert_str_eq(inf_add("5000000000000000", "2000000000000000"),
			 "7000000000000000" ,
			 "It must return 7000000000000000.\n" );
}

Test(inf_add, double_zero)
{
	cr_assert_str_eq(inf_add("0" , "0"), "0", "It must return 0.\n");
}

Test(inf_add, minus_zero)
{
	cr_assert_str_eq(inf_add("-0" , "-0"), "0", "It must return 0.\n");
}

Test(inf_add, bigger_double_minus)
{
	cr_assert_str_eq(inf_add("5000000000000000", "3000000000000000"),
			"8000000000000000",
			"It must return 8000000000000000.\n");
}
