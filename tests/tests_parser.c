/*
** EPITECH PROJECT, 2017
** tests_parser.c
** File description:
** Unit tests for pre_parser.c
*/

#include <criterion/criterion.h>
#include "postfix.h"
#include "utils.h"

Test(parser, empty_string)
{
	char *got = parser(my_strdup(""), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "",
			 "Got : %s | Expected : \"\"", got);
}

Test(parser, nothing_to_change_in_little_addition)
{
	char *got = parser(my_strdup("1+2"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "1+2",
			 "Got : %s | Expected : 1+2", got);
}

Test(parser, two_plus_past_in_little_addition)
{
	char *got = parser(my_strdup("3++5"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "3+5",
			 "Got : %s | Expected : 3+5", got);
}

Test(parser, 15_plus_past_in_little_addition)
{
	char *got = parser(my_strdup("6+++++++++++++++4"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "6+4",
			 "Got : %s | Expected : 6+4", got);
}

Test(parser, one_addition_in_parenthesis)
{
	char *got = parser(my_strdup("(7+9)"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "(7+9)",
			 "Got : %s | Expected : (7+9)", got);
}

Test(parser, nothing_to_change_in_little_substraction)
{
	char *got = parser(my_strdup("1-2"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "1-2",
			 "Got : %s | Expected : 1-2", got);
}

Test(parser, two_minus_past_in_little_substraction)
{
	char *got = parser(my_strdup("3--5"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "3+5",
			 "Got : %s | Expected : 3+5", got);
}

Test(parser, 15_minus_past_in_little_substraction)
{
	char *got = parser(my_strdup("6---------------4"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "6-4",
			 "Got : %s | Expected : 6-4", got);
}

Test(parser, one_substraction_in_parenthesis)
{
	char *got = parser(my_strdup("(7-9)"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "(7-9)",
			 "Got : %s | Expected : (7-9)", got);
}

Test(parser, plus_and_minus_past_and_parenthesis)
{
	char *got = parser(my_strdup("(9+-+-9)"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "(9+9)",
			 "Should return (9+9)", got);
}

Test(parser, plus_and_minus_past_nb_2_digits_and_parenthesis)
{
	char *got = parser(my_strdup("(98+-+-35)"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "(98+35)",
			 "Got : %s | Expected : (98+35)", got);
}


Test(parser, 2_plus_and_minus_past_nb_3_digits_and_parenthesis)
{
	char *got = parser(my_strdup("(808--+355-------+453)"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "(808+355-453)",
			 "Got : %s | Expected : (808+355-453)", got);
}

Test(parser, plus_and_minus_past_and_lot_of_parenthesis)
{
	char *got = parser(my_strdup("((98+-345)+-(35++++24)---2443++-+-+-+(-(234+324---54)))"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "((98-345)-(35+24)-2443-(-(234+324-54)))",
			 "Got : %s | Expected : ((98-345)-(35+24)-2443-(-(234+324-54)))", got);
}

Test(parser, start_lot_parenthesis)
{
	char *got = parser(my_strdup("--+---+-++++-((98+-345)+-(35++++24)---2443++-+-+-+(-(234+324---54)))"), my_strdup("()+-*/%"));

	cr_assert_str_eq(got, "-((98-345)-(35+24)-2443-(-(234+324-54)))",
			 "Got : %s | Expected : -((98-345)-(35+24)-2443-(-(234+324-54)))", got);
}
