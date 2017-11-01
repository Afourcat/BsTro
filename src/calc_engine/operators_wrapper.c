/*
** EPITECH PROJECT, 2017
** operators_wrapper.c
** File description:
** Wrapper ofthe operators
*/

#include <infin_sub.h>
#include <infin_sub.h>
#include <infin_mul.h>
#include <infin_div.h>
#include <infin_mod.h>

/**
 * \fn char *my_add (char *nb1, char *nb2)
 * \brief Function that wrap the infin_add function for maintability means.
 * \param nb1 The nb1 to be passed in the infin_add as second argument
 * \param nb2 The nb2 to be passed in the infin_add as second argument
 * \return The result of the infin_add(nb1, nb2).
 */
char *my_add(char *nb1, char *nb2)
{
	return (infin_add(nb1, nb2));
}

/**
 * \fn char *my_sub (char *nb1, char *nb2)
 * \brief Function that wrap the infin_sub function for maintability means.
 * \param nb1 The nb1 to be passed in the infin_sub as second argument
 * \param nb2 The nb2 to be passed in the infin_sub as second argument
 * \return The result of the infin_sub(nb1, nb2).
 */
char *my_sub(char *nb1, char *nb2)
{
	return (infin_sub(nb1, nb2));
}

/**
 * \fn char *my_mul (char *nb1, char *nb2)
 * \brief Function that wrap the infin_mul function for maintability means.
 * \param nb1 The nb1 to be passed in the infin_mul as second argument
 * \param nb2 The nb2 to be passed in the infin_mul as second argument
 * \return The result of the infin_mul(nb1, nb2).
 */
char *my_mul(char *nb1, char *nb2)
{
	return (infin_mul(nb1, nb2));
}

/**
 * \fn char *my_div (char *nb1, char *nb2)
 * \brief Function that wrap the infin_div function for maintability means.
 * \param nb1 The nb1 to be passed in the infin_div as second argument
 * \param nb2 The nb2 to be passed in the infin_div as second argument
 * \return The result of the infin_div(nb1, nb2).
 */
char *my_div(char *nb1, char *nb2)
{
	return (infin_div(nb1, nb2));
}

/**
 * \fn char *my_mod (char *nb1, char *nb2)
 * \brief Function that wrap the infin_mod function for maintability means.
 * \param nb1 The nb1 to be passed in the infin_mod as second argument
 * \param nb2 The nb2 to be passed in the infin_mod as second argument
 * \return The result of the infin_mod(nb1, nb2).
 */
char *my_mod(char *nb1, char *nb2)
{
	return (infin_div(nb1, nb2));
}
