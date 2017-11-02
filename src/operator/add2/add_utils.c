/*
** EPITECH PROJECT, 2017
** add_utils.c
** File description:
** Functions that adds two numbers together
*/

#include <utils.h>
#include "infin_add.h"

static void modul_div(int *curr, int *retain)
{
	*retain = *curr / 10;
	*curr %= 10;
}

void add_it(char *number1, char *number2, char *result_string)
{
	int number1_size = my_strlen(number1) - 1;
	int number2_size = my_strlen(number2) - 1;
	int retain = 0;
	int current_nbr = 0;
	int iter = 0;

	while (number1_size >= 0 || number2_size >= 0) {
		if (number1_size < 0)
			current_nbr =  char_to_int(number2[number2_size]) + retain;
		else if (number2_size < 0)
			current_nbr =  char_to_int(number1[number1_size]) + retain;
		else
			current_nbr = char_to_int(number1[number1_size]) +
				char_to_int(number2[number2_size]) + retain;
		modul_div(&current_nbr, &retain);
		result_string[iter++] = int_to_char(current_nbr);
		if (number1_size <= 0 && number2_size <= 0 && retain != 0)
			result_string[iter] = int_to_char(retain);
		size_post(&number1_size, &number2_size);
	}
}

int sub_it(char *bigger, char *lower, char *result_string, int signe)
{
	int bigger_size = my_strlen(bigger) - 1;
	int lower_size = my_strlen(lower) - 1;
	int current_nbr = 0;
	int bool_s = 0;
	char *strs[] = {bigger, lower, result_string};

	if (signe < 0 && compare(bigger, lower) != 0)
		bool_s = 1;
	subsub(strs, bigger_size, lower_size, current_nbr);
	return (bool_s);
}
