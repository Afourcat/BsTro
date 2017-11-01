/*
** EPITECH PROJECT, 2017
** infinadd.c
** File description:
** infinite addition with two arg
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_add.h"

/**
 * \fn int infin_add_wrapped(char **nb1, char **nb2, int size, char *result_string)
 * \brief Function wrapped by infin_add function remove minus and launch an add
 * if there is zero or two negative number and the sub otherwise.
 * \param nb1 The first number 
 * \param nb2 The second number 
 * \param size The size of the result string 
 * \param result_string the result string pointer. 
 * \return return a boolean about the result -1 if negative 1 if positive.
 */
int infin_add_wrapped(char **nb1, char **nb2, int size, char *result_string)
{
	int signe_1 = test_signe(*nb1);
	int signe_2 = test_signe(*nb2);
	int bool_s = 0;
	
	*nb1 = remove_minus(*nb1);
	*nb2 = remove_minus(*nb2);
	if (signe_1 == -1 && signe_2 == -1) {
		add_it(*nb1, *nb2, result_string);
		if (*nb1[0] != '0' && *nb2[0] != '0')
			bool_s = 1;
	}
	else if (signe_1 == -1 || signe_2 == -1) {
		if (compare(*nb1, *nb2) == 1)
			bool_s = sub_it(*nb1, *nb2, result_string, signe_1);
		else
			bool_s = sub_it(*nb2, *nb1, result_string, signe_2);
	}
	else
		add_it(*nb1, *nb2, result_string);
	return (bool_s);
}
/**
 * \fn char *infin_add(char *nb1, char *nb2)
 * \brief Function that wrap infin_add_wrapped, compute the size of the result
 * string and allocate it, then free his params.
 * \param nb1 First number 
 * \param nb2 Second number
 * \return return the result string of the addition of nb1 and nb2
 */
char *infin_add(char *nb1, char *nb2)
{
	int size = (my_strlen(nb1) > my_strlen(nb2) ?
		    my_strlen(nb1) : my_strlen(nb2));
	char *result_string = my_calloc(sizeof(char) * (size + 2));
	int bool = 0;
	
	bool = infin_add_wrapped(&nb1, &nb2, size, result_string);
	my_revstr(result_string);
	free(nb1);
	free(nb2);
	return (my_dup_without_zero(result_string, bool));
}
