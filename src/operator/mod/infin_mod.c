/*
** EPITECH PROJECT, 2017
** infin_mod.c
** File description:
** infinite modulo functions
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_sub.h>
#include <infin_mul.h>
#include <infin_div.h>

char *infin_mod(char *str1, char *str2)
{
        char *div = infin_div(str1, str2);
	char *mul = infin_mul(str2, div);
	char *mod = infin_sub(str1, mul);
	
	free(div);
	free(mul);
	return(mod);
}
