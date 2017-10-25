/*
** EPITECH PROJECT, 2017
** tests_postfix.c
** File description:
** Postfix test file
*/

#include <criterion/criterion.h>
#include <postfix.h>

Test(postfix, basic)
{
	char *infix = "1";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"1",
			"Should return 1");
}

Test(postfix, one_ope)
{
	char *infix = "1+2";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"1 2 +",
			"Should return 1 2 +");
}

Test(postfix, multiple_digits)
{
	char *infix = "10+20";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"10 20 +",
			"Should return 10 20 +");
}

Test(postfix, priority)
{
	char *infix = "1+2*3";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"1 2 + 3 *",
			"Should return 1 2 + 3 *");
}

Test(postfix, parenthesis)
{
	char *infix = "1+(2*3)";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"2 3 * 1 +",
			"Should return 2 3 * 1 +");
}

Test(postfix, relatives)
{
	char *infix = "-1+(-2*3)";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"-2 3 * -1 +",
			"Should return -2 3 * -1 +");
}

Test(postfix, overcomplicated)
{
	char *infix = "6*8/5+(4/2)";
	char *operands = "+-*/%";
	char *base = "0123456789";
	char *parent = "()";

	cr_assert_eq(postfix(infix, operands, base, parent),
			"6 8 * 5 / 4 / 2 +",
			"Should return 6 8 * 5 / 4 / 2 +");
}
