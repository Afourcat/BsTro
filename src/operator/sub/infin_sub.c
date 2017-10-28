/*
** EPITECH PROJECT, 2017
** infinsub.c
** File description:
** Infinite substraction with two string
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_add.h>

char *infin_sub(char *nb1, char *nb2)
{
	char *result;
	char *new_nb2 = get_opposed_number(nb2);

	result = infin_add(nb1, new_nb2);
	return (result);
}
