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
	if (str2[0] == '1' && str2[1] == '\0')
		return (str1);
	else
		return(infin_mul(infin_pow(str1, infin_sub(str2, "1")), str1));
}