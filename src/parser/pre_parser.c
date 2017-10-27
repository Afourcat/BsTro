/*
** EPITECH PROJECT, 2017
** pre_parser.h
** File description:
** Pre parser functions
*/

#include <utils.h>
#include <my.h>

char *find_neg(char *neg, char *operands, char *base);

char *pre_parser(char *str, char *operands, char *base)
{
	char *neg = my_calloc(2);
	int i = 0;
	int offset = 0;

	find_neg(neg, operands, base);
	str[i++] = (str[i] == operands[3] ? neg[1] : str[i]);
	while (str[i]) {
		if (str[i + offset] == operands[2] || str[i + offset] == operands[3])
			offset = offset + ope_or_rel(str, i, neg, operands);
		str[i++] = str[i + offset];
	}
	return (neg);
}

int ope_or_rel(char *str, int i, char *neg, char *ope)
{
	int offset = 0;
	int final = 1;
	int counter = 0;

	if (is_in(str[i - 1], ope) && str[i - 1] != ope[1])
		while (str[i + offset] == ope[2] || str[i + offset] == ope[3])
			offset++;
	while (counter < offset)
		final = final * (str[i + counter++] == ope[2] ? 1 : -1);
	if (offset >= 1) {
		str[i] = final == -1 ? neg[1] : ' ';
		offset = final == -1 ? offset - 1: offset;
	}
	return (offset);
}
