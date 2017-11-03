/*
** EPITECH PROJECT, 2017
** infin_mul.c
** File description:
** Multiplication operator
*/

#include "utils.h"
#include "infin_add.h"
#include "infin_mul.h"

static char *add_all(char **res, char **buffer, int size_nb2)
{
	for (int i = size_nb2 - 1; i >= 0; i--) {
		my_revstr(buffer[i]);
		*res = infin_add(*res, buffer[i]);
	}
	return (*res);
}

static int multiply(int nb1, int nb2, int *retain)
{
	int current_nb = nb1 * nb2 + *retain;

	if (current_nb > 9) {
		*retain = current_nb / 10;
		current_nb %= 10;
	} else
		*retain = 0;
	return (current_nb);
}

static char *mul_it(char *nb1, char *nb2, char **buffer, char **res)
{
	int size_nb1 = my_strlen(nb1);
	int size_nb2 = my_strlen(nb2);
	int ret = 0;
	int i = 0;
	int current_nb = 0;
	int buff_nb = 0;

	for (int l = size_nb2 - 1; l >= 0; l--, buff_nb++, ret = 0, i = 0) {
		add_zeros(buffer[buff_nb], buff_nb, &i);
		for (int g = size_nb1 - 1; g >= 0; g--) {
			current_nb = multiply(CHAR_TO_INT(nb1[g]),
					      CHAR_TO_INT(nb2[l]), &ret);
			buffer[buff_nb][i++] = INT_TO_CHAR(current_nb);
		}
		if (ret != 0)
			buffer[buff_nb][i] = INT_TO_CHAR(ret);
	}
	add_all(res, buffer, size_nb2);
	free(buffer);
	return (*res);
}

static char *mul_wrapper(char *nb1, char *nb2, int bool_s)
{
	int sizes_nb[] = {my_strlen(nb1), my_strlen(nb2)};
	char *res = my_calloc(sizeof(char) * 2);
	char **buffer = allocate_buffer(sizes_nb);
	int greatest = (sizes_nb[0] > sizes_nb[1]) ? 1 : 2;

	res[0] = '0';
	if (greatest == 1)
		mul_it(nb1, nb2, buffer, &res);
	else
		mul_it(nb2, nb1, buffer, &res);
	if (bool_s == 1) {
		res = add_sign(res, sizes_nb[0] + sizes_nb[1]);
	}
	return (res);
}

char *infin_mul(char *nb1, char *nb2)
{
	int sign_nb1 = get_sign_ope(&nb1);
	int sign_nb2 = get_sign_ope(&nb2);
	int bool_s = 0;
	char *res;

	if (sign_nb1 != sign_nb2 && (sign_nb1 == -1 || sign_nb2 == -1))
		bool_s = 1;
	res = mul_wrapper(nb1, nb2, bool_s);
	free_sign_ope(nb1, nb2, sign_nb1, sign_nb2); // Changer le nom
	return (res);
}
