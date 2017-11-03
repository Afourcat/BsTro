/*
** EPITECH PROJECT, 2017
** parse_neg.c
** File description:
** parse a neg expression
*/

#include "utils.h"

static void check_neg_number(char *expr, char *res, int *iters, char **bases);
static void manage_bracket(char *expr, char *res, int *iters, char **bases);
static void manage_number(char *expr, char *res, int *iters, char **bases);

static int get_nb_neg(char *str, char neg)
{
	int i = 0;
	int count = 0;

	while (str[i])
		if (str[i++] == neg)
			count++;
	return (count);
}

static void add_neg(char *op_base, char *nb_base, char *res)
{
	char *tmp = my_calloc(sizeof(char) * 2);

	tmp[0] = op_base[0];
	my_strcat(res, tmp);
	tmp[0] = nb_base[0];
	my_strcat(res, tmp);
	tmp[0] = op_base[3];
	my_strcat(res, tmp);
	free(tmp);
}

static void manage_number(char *expr, char *res, int *iters, char **bases)
{
	char *tmp = my_calloc(sizeof(char) * 2);

	tmp[0] = bases[1][2];
	if (iters[0] && (!is_in(iters[0 - 1], bases[1]) &&
			 expr[iters[0] - 1] != bases[1][0]))
		my_strcat(res + iters[1]++, tmp);
	add_neg(bases[1], bases[0], res);
	while (is_in(expr[++iters[0]], bases[0])) {
		tmp[0] = expr[iters[0]];
		my_strcat(res + iters[1]++, tmp);
	}
	iters[0]--;
	tmp[0] = bases[1][1];
	my_strcat(res + iters[1]++ ,tmp);
	free(tmp);
}

static void manage_bracket(char *expr, char *res, int *iters, char **bases)
{
	char *tmp = my_calloc(sizeof(char) * 2);
	
	tmp[0] = bases[1][2];
	if (iters[0] && (expr[iters[0] - 1] != bases[1][0] &&
			 !is_in(iters[0 - 1], bases[1])))
		my_strcat(res + iters[1]++, tmp);
	add_neg(bases[1], bases[0], res);
	tmp[0] = bases[1][0];
	my_strcat(res + iters[1]++, tmp);
	iters[0] += 2;
	check_neg_number(expr, res, iters, bases);
	iters[0]--;
	tmp[0] = bases[1][1];
	my_strcat(res + iters[1]++ ,tmp);
	free(tmp);
}

static void check_neg_number(char *expr, char *res, int *iters, char **bases)
{
	int depth = 1;
	char *tmp = my_calloc(sizeof(char) * 2);

	do {
	        if (expr[iters[0]] == bases[1][3] &&
		    expr[iters[0] + 1] == bases[1][0]) {
			manage_bracket(expr, res, iters, bases);
		} else if (expr[iters[0]] == bases[1][3]) {
			manage_number(expr, res, iters, bases);
		} else {
			tmp[0] = expr[iters[0]];
			my_strcat(res + iters[1]++, tmp);
		}
		depth = (expr[iters[0]] == bases[1][0]) ? depth + 1 : depth;
		depth = (expr[iters[0]++] == bases[1][1]) ? depth - 1 : depth;
	} while (depth != 0);
	free(tmp);
}

char *parse_neg(char *expr, char *nb_base, char *op_base)
{
	int iters[2] = {-1 , 0};
	int nb_neg = get_nb_neg(expr, op_base[3]);
	int size = my_strlen(expr) + ( 4 * get_nb_neg(expr, op_base[3]));
	printf("nb neg : |%d| x3 |%d|\n", nb_neg, nb_neg * 3);
	printf("strlen expr : |%d|\n", my_strlen(expr));
	printf("size : %d\n", size);
	char *res = my_calloc(sizeof(char) * (size + 1));
	char *tmp = my_calloc(sizeof(char) * 2);
	char *bases[] = {nb_base, op_base};

	while (expr[++iters[0]]) {
		if (expr[iters[0]] == op_base[3] &&
		    expr[iters[0] + 1] == op_base[0]) {
			manage_bracket(expr, res, iters, bases);
		} else if (expr[iters[0]] == op_base[3]) {
			manage_number(expr, res, iters, bases);
		} else {
			tmp[0] = expr[iters[0]];
			my_strcat(res + iters[1]++, tmp);
		}
	}
	free(expr);
	free(tmp);
	return (res);
}
