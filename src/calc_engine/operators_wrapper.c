/*
** EPITECH PROJECT, 2017
** operators_wrapper.c
** File description:
** Wrapper ofthe operators
*/

#include <infin_add.h>
#include <infin_sub.h>
#include <infin_mul.h>
#include <infin_div.h>
#include <infin_mod.h>

char *my_add(char *nb1, char *nb2)
{
	return (infin_add(nb1, nb2));
}

char *my_sub(char *nb1, char *nb2)
{
	return (infin_sub(nb1, nb2));
}

char *my_mul(char *nb1, char *nb2)
{
	return (infin_mul(nb1, nb2));
}

char *my_div(char *nb1, char *nb2)
{
	return (infin_div(nb1, nb2));
}

char *my_mod(char *nb1, char *nb2)
{
	return (infin_mod(nb1, nb2));
}
