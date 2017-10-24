/*
** EPITECH PROJECT, 2017
** infin_add.c
** File description:
** Core functions for infinadd
*/

#include <stdlib.h>
#include <infin_add.h>

int calc(int nb1, int nb2, int *retain)
{
	int res;

	res = nb1 + nb2 + *retain;
	if (res >= 10) {
		*retain = res / 10;
		res = res % 10;
	} else
		*retain = 0;
	return (res);
}

int calc_neg(int nb1, int nb2, int *retain)
{
	int res;

	if (nb1 >= nb2 + *retain) {
		res = nb1 - (nb2 + *retain);
		*retain = 0;
	} else {
		nb1 += 10;
		res = nb1 - (nb2 + *retain);
		*retain = 1;
	}
	return (res);
}

void init(char **str1, char **str2, int *signe1, int *signe2)
{
	int size_str1 = 0;
	int size_str2 = 0;

	*str1 = update(*str1, *signe1, &size_str1);
	*str2 = update(*str2, *signe2, &size_str2);
	*str1 = add_zeros(*str1, size_str2 + 1);
	*str2 = add_zeros(*str2, size_str1 + 1);
}

char *inf_add(char *first_nbr, char *second_nbr)
{
	int size;
	int current_nbr;
	char *buffer_res;
	int retain = 0;
	int i = 0;
	int signe_f = get_signe(first_nbr);
	int signe_s = get_signe(second_nbr);

	init(&first_nbr, &second_nbr, &signe_f, &signe_s);
	size = my_strlen(first_nbr) - 1;
	buffer_res = get_buffer(size);
	print_signe(&first_nbr, &second_nbr, &signe_f, &signe_s);
	while (size >= 0) {
		if (signe_f == signe_s)
			current_nbr = calc(charToInt(first_nbr[size]),
					       charToInt(second_nbr[size]),
					       &retain);
		else
			current_nbr = calc_neg(charToInt(first_nbr[size]),
					       charToInt(second_nbr[size]),
					       &retain);
		buffer_res[i++] = intToChar(current_nbr);
		size--;
	}
	return (my_revstr(buffer_res));
}
