/*
** EPITECH PROJECT, 2017
** infin_div.c
** File description:
** Infinite division function
*/

#include "infin_add.h"
#include "infin_sub.h"
#include "utils.h"
#include "error.h"

void set_buffer(char *buffer, char * str, int size)
{
	for (int i = 0; i < size; i++)
		buffer[i] = str[i];
}

char *get_quot(char **buffer, char *divisor)
{
	char *tmp_buffer = my_strdup(*buffer);
	char *quot = my_strdup("");
	int cmp = compare(tmp_buffer, divisor);

	if (buffer[0][0] == '0') {
		free(tmp_buffer);
		free(quot);
		return (my_strdup("0"));
	}
	while (cmp == 1 || cmp == 0) {
		tmp_buffer = infin_sub(tmp_buffer, my_strdup(divisor));
		if (tmp_buffer[0] != '-') {
			quot = infin_add(quot, my_strdup("1"));
			free(*buffer);
			*buffer = my_strdup(tmp_buffer);
		}
		cmp = compare(tmp_buffer, divisor);
	}
	free(tmp_buffer);
	return (quot);
}

char *infin_div_wrapped(char *dividend, char *divisor, int s_dend, int s_sor)
{
	char *quotient = my_calloc(sizeof(char) * (s_dend + 1));
	char *buffer = my_calloc(sizeof(char) * (s_sor + 2));
	char *tmp_quot;
	char *tmp = my_calloc(sizeof(char) * 2);

	set_buffer(buffer, dividend, s_sor);
	for (int i = s_sor - 1; i < s_dend; i++) {
		tmp_quot = get_quot(&buffer, divisor);
		my_strcat(quotient, tmp_quot);
		if (buffer[0] == '0')
			buffer[0] = 0;
		if (compare(divisor, buffer) == 1) {
			tmp[0] = dividend[i + 1];
			my_strcat(buffer, tmp);
		}
		free(tmp_quot);
	}
	free(tmp);
	free(buffer);
	if (quotient[0] == 0)
		quotient[0] = '0';
	return (quotient);
}

char *infin_div(char *dividend, char *divisor)
{
	int sign_dividend = get_sign_ope(&dividend);
	int sign_divisor = get_sign_ope(&divisor);
	char *res;
	int s_divisor;
	int s_dividend;

	if (compare(divisor, "0") == 0) {
		my_putstr_error("error");
		exit(84);
	}
	s_dividend = my_strlen(dividend);
	s_divisor = my_strlen(divisor);
	if (s_divisor > s_dividend) {
		free_sign_ope(dividend, divisor, sign_dividend, sign_divisor);
		return (my_strdup("0"));
	}
	res = infin_div_wrapped(dividend, divisor, s_dividend, s_divisor);
	if (sign_dividend != sign_divisor)
		res = my_dup_without_zero(res, 1);
	free_sign_ope(dividend, divisor, sign_dividend, sign_divisor);
	return (res);
}
