/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file of the project
*/

#include <stdlib.h>
#include <unistd.h>
#include "bistro_matic.h"
#include "utils.h"

static void check_base(char *av);
static void check_ops(char *ops);
static char *get_expr(unsigned size);

int main(int ac, char const *av[])
{
	char *expr;
	unsigned int size;

	if (ac != 4) {
		my_putstr("Usage: ");
		my_putstr(av[0]);
		my_putstr(" base ops \"()+-*/%\" exp_len\n");
		return (EXIT_USAGE);
	}
	check_base(av[1]);
	check_ops(av[2]);
	size = my_atoi(av[3]);
	expr = get_expr(size);
	my_putstr(eval_expr(av[1], av[2], expr, size));
	return (EXIT_SUCCESS);
}

static void check_base(char *b)
{
	if (my_strlen(b) < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
	}
}

static char *get_expr(unsigned int size)
{
	char *expr;

	if (size <= 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_SIZE_NEG);
	}
	expr = malloc(size + 1);
	if (expr == 0) {
		my_putstr(ERROR_MSG);
		exit (EXIT_MALLOC);
	}
	if (read(0, expr, size) != size) {
		my_putstr(ERROR_MSG);
		exit (EXIT_READ);
	}
	expr[size] = 0;
	return (expr);
}

static void check_ops(char *ops) {
	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
}
