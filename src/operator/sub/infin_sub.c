/*
** EPITECH PROJECT, 2017
** infinsub.c
** File description:
** Infinite substraction with two string
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_add.h>
#include <infin_sub.h>

char *get_oposed_number(char *nb)
{
	if (nb[0] == '-')
		nb = my_dup_without_zero(nb, 0);
	else
		nb = my_dup_without_zero(nb, 1);
	return (nb);
}

char *infin_sub(char *nb1, char *nb2)
{
	char *result;
	char *new_nb2 = get_oposed_number(nb2);

	result = infin_add(nb1, new_nb2);
	return (result);
}
