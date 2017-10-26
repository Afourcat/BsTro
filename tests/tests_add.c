/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test for add and substract system
*/

#include <infinadd.h>
#include <criterion/criterion.h>

Test(infin_add, basic)
{
	cr_assert_str_eq(infin_add("2", "4"), "6", "It must return 6.\n");
}

Test(infin_add, bigger_than_int)
{
	cr_assert_str_eq(infin_add("5000000000000000", "2000000000000000"),
			 "7000000000000000" ,
			 "It must return 7000000000000000.\n" );
}

Test(infin_add, double_zero)
{
	cr_assert_str_eq(infin_add("0" , "0"), "0", "It must return 0.\n");
}

Test(infin_add, minus_zero)
{
	cr_assert_str_eq(infin_add("-0" , "-0"), "0", "It must return 0.\n");
}

Test(infin_add, bigger_double_minus)
{
	cr_assert_str_eq(infin_add("1000000000000000000000000000000000000000000000",
				   "1000000000000000000000000000000000000000000000"),
			           "2000000000000000000000000000000000000000000000",
			"It must return 8000000000000000000000000000000000000000.\n");
}
