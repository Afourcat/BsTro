/*
** EPITECH PROJECT, 2017
** mul_conv.c
** File description:
** conversion for multiply
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_add.h"
#include "infin_mul.h"

void add_zeros(char *buffer, int nb_zeros, int *iter)
{
	int size = my_strlen(buffer);
	
	for (int i = size ; i < (size+ nb_zeros); i++) {
		buffer[i] = '0';
		(*iter)++;
	}
}

char *add_all(char **res, char **buffer, int size_l, int size_g)
{
	int counter = 0;
	
	for (int l = size_l - 1; l >= 0; --l) {
		buffer[l] = my_revstr(buffer[l]);
		*res = infin_add(*res, buffer[l]);
	}
	return (*res);
}
