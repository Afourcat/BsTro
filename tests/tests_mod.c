/*
** EPITECH PROJECT, 2017
** tests_mod.c
** File description:
** modulo test criterion
*/

#include <criterion/criterion.h>
#include "infin_mod.h"

Test(infin_mod, basic)
{
	cr_assert_str_eq(infin_mod("55", "20"), "15", "Should return 15.\n");
}

Test(infin_mod, by_one)
{
	cr_assert_str_eq(infin_mod("9933", "1"), "0", "Should return 0.\n");
}

Test(infin_mod, by_same)
{
	cr_assert_str_eq(infin_mod("55", "55"), "0", "Should return 0.\n");
}

Test(infin_mod, biggest_than_int)
{
	cr_assert_str_eq(infin_mod("12345678900", "56"), "44", "Should return 44.\n");
}

Test(infin_mod, big_nine)
{
	cr_assert_str_eq(infin_mod("9999", "5"), "4", "Should return 4.\n");
}

Test(infin_mod, negative)
{
	cr_assert_str_eq(infin_mod("9999", "-5"), "4", "Should return 4.\n");
}

Test(infin_mod, negative_2)
{
	cr_assert_str_eq(infin_mod("-3256", "25"), "-6", "Should return -6.\n");
}

Test(infin_mod, negative_3)
{
	cr_assert_str_eq(infin_mod("-578324", "-13"), "-6", "Should return -6.\n");
}
