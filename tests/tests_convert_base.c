/*
** EPITECH PROJECT, 2017
** tests_convert_base.c
** File description:
** convert_base test file
*/

#include <criterion/criterion.h>
#include "convert_base.h"

Test(convert_base, basic_to_hex)
{
	cr_assert_str_eq(convert_base("255", "0123456789ABCDEF", '-', 1),
			 "FF",
			 "Should return FF.\n");
}

Test(convert_base, basic_to_dec)
{
	cr_assert_str_eq(convert_base("4253", "012345", '-', 0),
			 "969",
			 "Should return 969.\n");
}

Test(convert_base, basic_to_hex_minus)
{
	cr_assert_str_eq(convert_base("-255", "0123456789ABCDEF", '-', 1),
			 "-FF",
			 "Should return -FF.\n");
}

Test(convert_base, basic_to_dec_minus)
{
	cr_assert_str_eq(convert_base("!4253", "012345", '!', 0),
			 "-969",
			 "Should return -969.\n");
}

Test(convert_base, dec_to_alpha)
{
	cr_assert_str_eq(convert_base("255", "abcdefghijklmnop", '-', 1),
			 "pp",
			 "Should return pp.\n");
}

Test(convert_base, alpha_to_dec)
{
	cr_assert_str_eq(convert_base("!pp", "abcdefghijklmnop", '!', 0),
			 "-255",
			 "Should return -255.\n");
}
