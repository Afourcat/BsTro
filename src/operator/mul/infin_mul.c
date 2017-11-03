/*
** EPITECH PROJECT, 2017
** mul.c
** File description:
** infinite multiplication functions
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_add.h"
#include "infin_mul.h"

int test_signe(char *str, char *op_base)
{
	int i = 1;

	if (str[0] == op_base[3])
		return (-1);
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == op_base[3]) {
			return (-1);
		}
		else if (str[i] >= '0' && str[i] <= '9' && str[i - 1] != op_base[3]) {
			return (1);
		}
		i++;
	}
	return (0);
}

char *add_signe(char *positive)
{
	int size = my_strlen(positive);
	char *new_re = my_calloc(sizeof(char) * (size + 2));
	int i = 1;
	int j = 0;

	new_re[0] = '-';
	while (positive[j] != '\0') {
		new_re[i] = positive[j];
		i++;
		j++;
	}
	new_re[i] = '\0';
	free(positive);
	return (new_re);
}

static int multiply(int a, int b, int *current, int *retain)
{
	int temp_retain = *retain;
	int bool = 0;

	(*current) = (a * b) + (*retain);
	if (*current > 9) {
		*retain = *current / 10;
		*current = ((*current) % 10);
		bool = 1;
	}
	else {
		*retain = 0;
	}
	return (bool);
}

static char *mul(char **strs, char **buffer, char **res, char *op_base)
{
	int size_g = my_strlen(strs[1]);
	int size_l = my_strlen(strs[0]);
	int ret = 0;
	int curr = 0;
	int iter = 0;
	int buff_nbr = 0;
	int b_l = 0;

	for (int l = size_l - 1; l >= 0 ; l-- , iter = 0, buff_nbr++, ret = 0) {
		add_zeros(buffer[buff_nbr], buff_nbr, &iter);
		for (int g = size_g - 1; g >= 0; g--) {
			b_l = multiply(char_to_int(strs[0][l])
				       , char_to_int(strs[1][g]), &curr, &ret);
			buffer[buff_nbr][iter++] = int_to_char(curr);
			if (g == 0 && b_l == 1)
				buffer[buff_nbr][iter++] = int_to_char(ret);
		}
	}
	*res = add_all(res, buffer, size_l, op_base);
	free_all(buffer, strs[1], strs[0]);
	return (*res);
}

static char *post_infin_mul(char *str1, char *str2, int bool_s, char *op_base)
{
	int size = my_strlen(str1) + my_strlen(str2);
	char *res = "0";
	char **buffer = allocate_buffer(str1, str2, size);
	int greatest = get_greatest(str1, str2);
	char *strs[2];

	if (greatest == 1) {
		strs[0] = str1;
		strs[1] = str2;
		res = mul(strs, buffer, &res, op_base);
	} else {
		strs[0] = str2;
		strs[1] = str1;
		res = mul(strs, buffer, &res, op_base);
	}
	if (bool_s == 1)
		res = add_signe(res);
	free(str1);
	free(str2);
	return (res);
}

char *infin_mul(char *str1, char *str2, char *op_base)
{
	int bool_s = 0;

	if (test_signe(str1, op_base) == -1 && test_signe(str2, op_base) == -1)
		bool_s = 0;
	else if (test_signe(str1, op_base) == -1 || test_signe(str2, op_base) == -1)
		bool_s = 1;
	str1 = remove_minus(str1);
	str2 = remove_minus(str2);
	return (post_infin_mul(str1, str2, bool_s, op_base));
}

