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
static void check_ops(char *op_base, char *nb_base);
static char *get_expr(unsigned const size);

int main(int ac, char *av[])
{
	char *expr;
	unsigned int size;
	char *res;

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
	res = eval_expr(av[1], av[2], expr, size);
	my_putstr(res);
	free(expr);
	free(res);
	return (EXIT_SUCCESS);
}

static void check_base(char *nb_base)
{
	int size_nb = my_strlen(nb_base);
	int res = 0;

	if (size_nb < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
	}
	for (int i = 0; i < size_nb - 1; i++)
		for (int j = i + 1; j < size_nb; j++)
			res += (nb_base[i] == nb_base[j]) ? 1: 0;
	if (res != 0) {
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
	expr = malloc(sizeof(char) * (size + 1));
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

static void check_ops(char *op_base, char *nb_base)
{
	int size_nb = my_strlen(nb_base);
	int size_op = my_strlen(op_base);
	int res = 0;

	if (size_op != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
	for (int i = 0; i < size_nb; i++)
	        for (int j = 0; j < size_op; j++)
			res += (nb_base[i] == op_base[i]) ? 1: 0;
	if (res != 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
}
