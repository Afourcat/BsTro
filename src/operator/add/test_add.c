/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test function for inifinite add
*/

#include <unistd.h>
#include "utils.h"

int test_signe(char *str)
{
	int i = 1;

	if (str[0] == '-')
		return (-1);
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

void size_post(int *size1, int *size2)
{
	(*size1)--;
	(*size2)--;
}

void subsub(char **strs, int bigger_size, int lower_size, int current_nbr)
{
	int tab[2] = {0, 0};
	
	while (bigger_size >= 0 || lower_size >= 0) {
	       	if (lower_size < 0)
			current_nbr = char_to_int(strs[0][bigger_size]) - tab[0];
		else {
			current_nbr = char_to_int(strs[0][bigger_size]) -
				char_to_int(strs[1][lower_size]) - tab[0];
		}
		if (current_nbr < 0) {
			current_nbr = char_to_int(strs[0][bigger_size]) + 10;
			current_nbr -= (lower_size < 0 ? 1 : char_to_int(strs[1][lower_size]) + tab[0]);
			tab[0] = 1;
		}
		else
			tab[0] = 0;
		strs[2][tab[1]] = int_to_char(current_nbr);
		tab[1]++;
		size_post(&bigger_size, &lower_size);
	}
}
