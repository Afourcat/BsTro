/*
** EPITECH PROJECT, 2017
** infin_mod.c
** File description:
** infinite modulo functions
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_sub.h"
#include "infin_mul.h"
#include "infin_div.h"

char *infin_mod(char *str1, char *str2)
{
	char *div = infin_div(my_strdup(str1), my_strdup(str2));
	char *mul = infin_mul(my_strdup(str2), my_strdup(div));
	char *mod = infin_sub(my_strdup(str1), mul);

	if (str1[0] == '-' && mod[0] != '-' && mod[0] != '0') {
		free(str1);
		free(str2);
		free(div);
		return (my_dup_without_zero(mod, 1));
	} else {
		free(str1);
		free(str2);
		free(div);
		return (mod);
	}
}
