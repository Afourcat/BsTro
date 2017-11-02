/*
** EPITECH PROJECT, 2017
** infinadd.c
** File description:
** infinite addition with two arg
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_add.h"

int infin_add_wrapped(char **nb1, char **nb2, int size, char *result_string)
{
	int signe_1 = test_signe(*nb1);
	int signe_2 = test_signe(*nb2);
	int bool_s = 0;

	*nb1 = remove_minus(*nb1);
	*nb2 = remove_minus(*nb2);
	if (signe_1 == -1 && signe_2 != -1 ||
		 signe_2 == -1 && signe_1 != -1) {
      		if (compare(*nb1, *nb2) == 1)
			bool_s = sub_it(*nb1, *nb2, result_string, signe_1);
		else
			bool_s = sub_it(*nb2, *nb1, result_string, signe_2);
	}
	else
		add_it(*nb1, *nb2, result_string);
	return (bool_s);
}

char *infin_add(char *nb1, char *nb2)
{
	int size = (my_strlen(nb1) > my_strlen(nb2) ?
		    my_strlen(nb1) : my_strlen(nb2));
	char *result_string = my_calloc(sizeof(char) * (size + 2));
	int bool = 0;

	bool = infin_add_wrapped(&nb1, &nb2, size, result_string);
	my_revstr(result_string);
	free(nb1);
	free(nb2);
	return (my_dup_without_zero(result_string, bool));
}
