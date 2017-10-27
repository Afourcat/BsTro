/*
** EPITECH PROJECT, 2017
** sub_it.c
** File description:
** sub two numbers together
*/

#include <infin_add.h>
#include <utils.h>

static int parse_current(int *current_nbr,char *bigger, char *lower, int *bigger_size, int *lower_size, int retain);
static void size_m(int *size1, int *size2);

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
		size_m(&bigger_size, &lower_size);
	}
	return (bool_s);
}

static void size_m(int *size1, int *size2)
{
	(*size1)--;
	(*size2)--;
}

int compare(char *bigger, char *lower) {
	int i = 0;

	if (my_strlen(lower) == my_strlen(bigger)) {
		while (bigger[i] == lower[i] && i < my_strlen(bigger)) {
			i++;
		}
		if (i == my_strlen(bigger))
			return (0);
		return (bigger[i] > lower[i] ? 1 : 2);
	}
	return (my_strlen(bigger) > my_strlen(lower) ? 1 : 2);
}
