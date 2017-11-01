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

/**
 * \fn char *infin_mod (char *str1, char *str2)
 * \brief Function that returns the modulo of two string number, the remainder
 * of the euclidean division of those two number
 * \param str1 The dividend of the division which remainder will be returned.
 * \param str2 The divisor of the division which remainder will be returned.
 * \return The remainder of the euclidean division of str1 and str2.
 */
char *infin_mod(char *str1, char *str2)
{
	char *div = infin_div(str1, str2);
	char *mul = infin_mul(str2, div);
	char *mod = infin_sub(str1, mul);

 	return(mod);
}
