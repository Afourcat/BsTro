/*
** EPITECH PROJECT, 2017
** neg_parser.c
** File description:
** check if the character is not in the base or in the operand
*/

#include "utils.h"
#include "my.h"

int find_neg(char *neg, char *operands, char *base)
{
	char c = '!';

	while (is_in(c, operands) || is_in(c, base))
		c++;
	neg[0] = operands[3];
	neg[1] = c;
	return (0);
}

int get_nb_neg(char *str, char *neg)
{
	int i = -1;
	int count = 0;

	while (str[++i])
		if (str[i] == neg[1])
			count++;
	return (count);
}

void manage_neg_brackets(char *str, char *res, int *ctrs, char *neg)
{
	my_strcat(res + ctrs[1], "(0");
	ctrs[1] += 2;
	my_strcat(res + ctrs[1]++, neg[0]);
	ctrs[0]++;
	while (str[ctrs[0]] != ')') {
		if (str[ctrs[0]] == neg[1])
			manage_neg_brackets(str, res, ctrs, neg);
		else
			my_strcat(res + ctrs[1]++, str + ctrs[0]);
		ctrs[0]++;
	}
	my_strcat(res + ctrs[1]++, str + ctrs[0]);
	my_strcat(res + ctrs[1]++, ")");
}

void manage_neg_number(char *str, char *res, int *ctrs, char *neg)
{
	my_strcat(res + ctrs[1], "(0");
	ctrs[1] += 2;
	my_strcat(res + ctrs[1]++, neg[0]);
	ctrs[0]++;
	while (str[ctrs[0]] >= '0' && str[ctrs[0]] <= '9') {
		my_strcat(res + ctrs[1]++, str + ctrs[0]++);
	}
	my_strcat(res + ctrs[1]++, ")");
}

char *parse_neg(char *str, char *neg)
{
	int ctrs[2] = {0, 0};
	int size = my_strlen(str) + (3 * get_nb_neg(str, neg));
	char *res = malloc(sizeof(char) * (size + 1));

	while (str[ctrs[0]]) {
		if (str[ctrs[0]] == neg[1] && str[ctrs[0] + 1] == '(') {
			manage_neg_brackets(str, res, ctrs, neg);
		} else {
			manage_neg_number(str, res, ctrs, neg);
		}
		ctrs[0]++;
	}
	free(str);
	return (res);
}
