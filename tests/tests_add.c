/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test for add and substract system
*/

#include <criterion/criterion.h>
#include "infin_add.h"
#include "utils.h"

Test(infin_add, basic)
{
	cr_assert_str_eq(infin_add(my_strdup("2"), my_strdup("4")), "6", "It must return 6.\n");
}

Test(infin_add, bigger_than_int)
{
	cr_assert_str_eq(infin_add(my_strdup("5000000000000000"), my_strdup("2000000000000000")),
			 "7000000000000000" ,
			 "It must return 7000000000000000.\n" );
}

Test(infin_add, double_zero)
{
	cr_assert_str_eq(infin_add(my_strdup("0") , my_strdup("0")), "0", "It must return 0.\n");
}

Test(infin_add, minus_z)
{
	cr_assert_str_eq(infin_add(my_strdup("-0"), my_strdup("-0")), "0", "It must return 0.\n");
}

Test(infin_add, bigger_doubus)
{
	cr_assert_str_eq(infin_add(my_strdup("1000000000000000000000000000000000000000000000"),
				   my_strdup("1000000000000000000000000000000000000000000000")),
			           "2000000000000000000000000000000000000000000000",
		    "It must return 2000000000000000000000000000000000000000000000.\n");
}

Test(infin_add, big_big)
{
	cr_assert_str_eq(infin_add(my_strdup("5000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"),
				   my_strdup("5000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")),
			          "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
		   "It must return 10.\n");
}
