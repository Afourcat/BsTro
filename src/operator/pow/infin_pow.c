/*
** EPITECH PROJECT, 2017
** infin_pow.c
** File description:
** Infinite multiplication functions
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_add.h>
#include <infin_sub.h>
#include <infin_mul.h>

char *infin_pow(char *str1, char *str2)
{
	char *temp;

	if (str2[0] == '0' && str2[1] == '\0')
		return (my_strdup("1"));
	if (str2[0] == '1' && str2[1] == '\0')
		return (str1);
	else {
		temp = infin_mul(infin_pow(my_strdup(str1), infin_sub(str2, my_strdup("1"))), str1);
		return (temp);
	}
}
