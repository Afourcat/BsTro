/*
** EPITECH PROJECT, 2017
** add_it.c
** File description:
** add two numbers together
*/

#include <infin_add.h>
#include <utils.h>

static void modul_div(int *curr, int *retain);
static void size_post(int *nbr1, int *nbr2);

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

static void size_post(int *nbr1, int *nbr2)
{
	(*nbr1)--;
	(*nbr2)--;
}

static void modul_div(int *curr, int *retain)
{
	*retain = *curr / 10;
	*curr %= 10;
}

char int_to_char(int i)
{
	return (i + 48);
}

int char_to_int(char c)
{
	return (c - 48);
}
