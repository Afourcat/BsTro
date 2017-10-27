/*
** EPITECH PROJECT, 2017
** tests_mul.c
** File description:
** mul function test
*/

Test(infin_mul, basic)
{
	cr_assert_str_eq(infin_mul("100", "10"), "1000",
			 "Should return 1000.\n");
}

Test(infin_mul, bigger_than_int)
{
	cr_assert_str_eq(infin_mul("2000000000000000000000000", "2")
			 , "4000000000000000000000000",
			 "Should return 4000000000000000000000000.\n");
}

Test(infin_mul, inferior_to_zero)
{
	cr_assert_str_eq(infin_mul("-123", "-23"), "2829",
			 "Should return 2829.\n");
}

Test(infin_mul, basic)
{
	cr_assert_str_eq(infin_mul("-11", "4"), "-44",
			 "Should return -44.\n");
}

Test(infin_mul, double_zero)
{
	cr_assert_str_eq(infin_mul("0", "0"), "0",
			 "Should return -44.\n");
}

Test(infin_mul, zero)
{
	cr_asser_str_eq(infin_mul("0", "400"), "0",
			"Should return 0.\n");
}

Test(infin_mul, bigger_right)
{
	cr_asser_str_eq(infin_mul("2", "123"), "246",
			"Should return 246.\n");
}
