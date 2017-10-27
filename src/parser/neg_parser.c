/*
** EPITECH PROJECT, 2017
** neg_parser.c
** File description:
** check if the character is not in the base or in the operand
*/

#include <utils.h>
#include <my.h>

int find_neg(char *neg, char *operands, char *base)
{
	char c = 33;
	
	while (is_in(c, operands) || is_in(c, base)) {
		c++;
	}
	neg[0] = operands[3];
	neg[1] = c;
	return (0);
}
