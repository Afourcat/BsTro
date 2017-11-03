/*
** EPITECH PROJECT, 2017
** parse_neg.c
** File description:
** Parse the minus for the negation of an expression
*/

#include <stdlib.h>
#include "utils.h"

static void manage_neg_brackets(char *str, char *res, int *ctrs, char **bases);
static void manage_neg_number(char *str, char *res, int *ctrs, char **bases);
static void check_neg_numbers(char *str, char *res, int *ctrs, char **bases);

static int get_nb_neg(char *str, char neg)
{
	int i = -1;
	int count = 0;

	while (str[++i])
		if (str[i] == neg)
			count++;
	return (count);
}

static void manage_neg_number(char *str, char *res, int *ctrs, char **bases)
{
	char *tmp = my_calloc(2);
	char operands[] = "(+-*/%";

	tmp[0] = bases[1][2];
	if (ctrs[0] && !is_in(str[ctrs[0] - 1], operands))
		my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[1][0];
	my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[0][0];
	my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[1][3];
	my_strcat(res + ctrs[1]++, tmp);
	while (is_in(str[++ctrs[0]], bases[0])) {
		tmp[0] = str[ctrs[0]];
		my_strcat(res + ctrs[1]++, tmp);
	}
	ctrs[0]--;
	tmp[0] = bases[1][1];
	my_strcat(res + ctrs[1]++, tmp);
	free(tmp);
}

static void manage_neg_brackets(char *str, char *res, int *ctrs, char **bases)
{
	char operands[] = "(+-*/%";
	char *tmp = my_calloc(2);

	tmp[0] = bases[1][2];
	if (ctrs[0] && !is_in(str[ctrs[0] - 1], operands))
		my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[1][0];
	my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[0][0];
	my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[1][3];
	my_strcat(res + ctrs[1]++, tmp);
	tmp[0] = bases[1][0];
	if (str[ctrs[0] + 1] == bases[1][0])
		my_strcat(res + ctrs[1]++, tmp);
	ctrs[0] += (str[ctrs[0] + 1] == bases[1][0]) ? 2 : 1;
	check_neg_numbers(str, res, ctrs, bases);
	ctrs[0]--;
	tmp[0] = bases[1][1];
	my_strcat(res + ctrs[1]++, tmp);
	free(tmp);
}

static void check_neg_numbers(char *str, char *res, int *ctrs, char **bases)
{
	int depth = 1;
	char *tmp = my_calloc(2);

	do {
		if (str[ctrs[0]] == bases[1][3] &&
		    str[ctrs[0] + 1] == bases[1][0])
			manage_neg_brackets(str, res, ctrs, bases);
		else if (str[ctrs[0]] == bases[1][3])
			manage_neg_number(str, res, ctrs, bases);
		else {
			tmp[0] = str[ctrs[0]];
			my_strcat(res + ctrs[1]++, tmp);
		}
		depth = (str[ctrs[0]] == bases[1][0]) ? depth + 1 : depth;
		depth = (str[ctrs[0]++] == bases[1][1]) ? depth - 1 : depth;
	} while (depth != 0);
	free(tmp);
}

char *parse_neg(char *str, char *nb_base, char *op_base)
{
	int ctrs[2] = {-1, 0};
	int size = my_strlen(str) + (3 * get_nb_neg(str, op_base[3]));
	char *res = my_calloc(size + 1);
	char *tmp = my_calloc(2);
	char *bases[] = {nb_base, op_base};

	while (str[++ctrs[0]])
		if (str[ctrs[0]] == op_base[3] &&
		    str[ctrs[0] + 1] == op_base[0]) {
			manage_neg_brackets(str, res, ctrs, bases);
		} else if (str[ctrs[0]] == op_base[3]){
			manage_neg_number(str, res, ctrs, bases);
		} else {
			tmp[0] = str[ctrs[0]];
			my_strcat(res + ctrs[1]++, tmp);
		}
	res[ctrs[1]] = 0;
	free(str);
	return (res);
}
