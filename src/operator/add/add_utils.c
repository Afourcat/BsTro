/*
** EPITECH PROJECT, 2017
** add_utils.c
** File description:
** Functions that adds two numbers together
*/

#include <utils.h>

static void modul_div(int *curr, int *retain)
{
	*retain = *curr / 10;
	*curr %= 10;
}

static void size_post(int *size1, int *size2)
{
	(*size1)--;
	(*size2)--;
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
	int iter = 0;
	int retain = 0;
	int bool_s = 0;

	if (signe < 0 && compare(bigger, lower) != 0)
		bool_s = 1;
	while (bigger_size >= 0 || lower_size >= 0) {
	       	if (lower_size < 0)
			current_nbr = char_to_int(bigger[bigger_size]) - retain;
		else {
			current_nbr = char_to_int(bigger[bigger_size]) -
				char_to_int(lower[lower_size]) - retain;
		}
		if (current_nbr < 0) {
			current_nbr = char_to_int(bigger[bigger_size]) + 10;
			current_nbr -= (lower_size < 0 ? 1 : char_to_int(lower[lower_size]) + retain);
			retain = 1;
		}
		else
			retain = 0;
		result_string[iter] = int_to_char(current_nbr);
		iter++;
		size_post(&bigger_size, &lower_size);
	}
	return (bool_s);
}

int test_signe(char *str)
{
	int i = 0;

	while(str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == '-') {
			return (-1);
		}
		else if (str[i] >= '0' && str[i] <= '9' && str[i - 1] != '-') {
			return (1);
		}
		i++;
	}
	return (0);
}
