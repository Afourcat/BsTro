/*
** EPITECH PROJECT, 2017
** tests_mod.c
** File description:
** modulo test criterion
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "infin_mod.h"

Test(infin_mod, basic)
{
	cr_assert_str_eq(infin_mod(my_strdup("55"), my_strdup("20")), "15", "Should return 15.\n");
}

Test(infin_mod, by_one)
{
	cr_assert_str_eq(infin_mod(my_strdup("9933"), my_strdup("1")), "0", "Should return 0.\n");
}

Test(infin_mod, by_same)
{
	cr_assert_str_eq(infin_mod(my_strdup("55"), my_strdup("55")), "0", "Should return 0.\n");
}

Test(infin_mod, biggest_than_int)
{
	cr_assert_str_eq(infin_mod(my_strdup("12345678900"), my_strdup("56")), "44", "Should return 44.\n");
}

Test(infin_mod, big_nine)
{
	cr_assert_str_eq(infin_mod(my_strdup("9999"), my_strdup("5")), "4", "Should return 4.\n");
}

Test(infin_mod, negative)
{
	cr_assert_str_eq(infin_mod(my_strdup("9999"), my_strdup("-5")), "4", "Should return 4.\n");
}

Test(infin_mod, negative_2)
{
	cr_assert_str_eq(infin_mod(my_strdup("-3256"), my_strdup("25")), "-6", "Should return -6.\n");
}

Test(infin_mod, negative_3)
{
	cr_assert_str_eq(infin_mod(my_strdup("-578324"), my_strdup("-13")), "-6", "Should return -6.\n");
}
