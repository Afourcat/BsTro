/*
** EPITECH PROJECT, 2017
** infinsub.c
** File description:
** Infinite substraction with two string
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_add.h"

static char *my_dup_without_free(char *str, int bool)
{
	int j = 0;
	char *new_str = my_allocate(str, bool, &j);
	int i = 0;

	if (bool == 1) {
		new_str[0] = '-';
		i = 1;
	}
	else
		j = 1;
	while (str[j] == '0' && str[j + 1] != '\0')
		j++;
	while (str[j])
		new_str[i++] = str[j++];
	return (new_str);
}

static char *get_opposed_number_wo_free(char *nb)
{
	if (nb[0] == '-')
		nb = my_dup_without_free(nb, 0);
	else
		nb = my_dup_without_free(nb, 1);
	return (nb);
}

char *infin_sub(char *nb1, char *nb2, char *op_base)
{
	char *result;
	char *new_nb2 = get_opposed_number_wo_free(nb2);

	result = infin_add(nb1, new_nb2, op_base);
	return (result);
}
