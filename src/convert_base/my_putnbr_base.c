/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** Function that converts and display a decimal number into a number
** in a given base
*/

#include "utils.h"
#include "infin_add.h"
#include "infin_mul.h"
#include "infin_div.h"
#include "infin_sub.h"
#include "infin_pow.h"

static int put_in_str(char c, char *str)
{
	int size = my_strlen(str);

	str[size] = c;
	return (0);
}

static int get_max_power_of(char *nb, char *base)
{
	int temp_power = 0;

	while (compare(infin_pow(base, my_itoa(temp_power)), nb) == 2 ||
	       compare(infin_pow(base, my_itoa(temp_power)), nb) == 0) {
		temp_power++;
	}
	return (temp_power - 1);
}

static char *get_first_digit(char *nb, char *base, int max_power)
{
	int counter = 0;
	char *temp_number = my_strdup(nb);

	while (counter < max_power) {
		temp_number = infin_div(temp_number, base);
		counter++;
	}
	return (temp_number);
}

char *my_putnbr_base(char *nbr, char *base, char neg_base)
{
	char *nb = "0";
	char *to_return;
	char *nbr_base = "0";
	char *digit;
	char sign = 0;
	int max_power;

	if (nbr[0] == '-') {
		nb = remove_minus(nbr);
		sign = 1;
	} else
		nb = nbr;
	while (base[my_atoi(nbr_base)])
		nbr_base = infin_add(nbr_base, "1");
	max_power = get_max_power_of(nb, nbr_base);
	to_return = my_calloc(sizeof(char) * (max_power + 3));
	while (max_power >= 0) {
		digit = get_first_digit(nb, nbr_base, max_power);
		put_in_str(base[my_atoi(digit)], to_return);
		nb = infin_sub(nb, infin_mul(digit, infin_pow(nbr_base, my_itoa(max_power))));
		max_power--;
	}
	return (sign == 0 ? to_return : infin_mul(to_return, "-1"));
}
