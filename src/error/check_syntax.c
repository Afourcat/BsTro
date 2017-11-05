/*
** EPITECH PROJECT, 2017
** check_syntax.c
** File description:
** Main file for checking syntax errors
*/

#include <stdlib.h>
#include "utils.h"
#include "error.h"

static int check_operands(char *str, char *operands)
{
	if (is_in(str[my_strlen(str)], operands))
	    return (84);
	return (0);
}

static int check_parenthesis(char *str, char *operands)
{
	int counter = 0;
	int depth = 0;

	while (str[counter]) {
		if (str[counter] == operands[0])
			depth++;
		if (str[counter] == operands[0] && counter &&
		    !is_in(str[counter - 1], operands))
			return (84);
		if (str[counter] == operands[1])
			depth--;
		counter++;
	}
	return (depth == 0 ? 0 : 84);
}

static int check_base(char *str, char *operands, char *base)
{
	int counter = 0;

	while (str[counter]) {
		if (!is_in(str[counter], operands) &&
		    !is_in(str[counter], base))
			return (84);
		counter++;
	}
	return (0);
}

int check_syntax(char *str, char *operands, char *base)
{
	if (check_parenthesis(str, operands)) {
		my_putstr_error("syntax error");
		free(str);
		exit(84);
	}
	if (check_base(str, operands, base)) {
		my_putstr_error("syntax error");
		free(str);
		exit(84);
	}
	if (check_operands(str, operands)) {
		my_putstr_error("syntax error");
		free(str);
		exit(84);
	}
	return (0);
}
