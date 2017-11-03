/*
** EPITECH PROJECT, 2017
** get_base_to_dec
** File description:
** Function that converts a number into decimal number
*/

#include "utils.h"
#include "infin_add.h"
#include "infin_sub.h"
#include "infin_mul.h"
#include "infin_div.h"

static char *get_dig(char symbol, char const *base)
{
	int counter = 0;

	while (base[counter] != symbol)
		counter++;
	if (base[counter])
		return (my_itoa(counter));
	else
		return ("-1");
}

static char *get_base(char const *base)
{
	int counter = 0;

	while (base[counter])
		counter++;
	return (my_itoa(counter));
}

static int get_first_apearance(char const *str, char const *base)
{
	int str_counter = 0;
	int base_ctr = 0;

	while (str[str_counter]) {
		while (base[base_ctr] && str[str_counter] != base[base_ctr])
			base_ctr++;
		if (base[base_ctr])
			return (str_counter);
		str_counter++;
		base_ctr = 0;
	}
	return (0);
}

char *get_base_to_dec(char *str, char *base, char neg)
{
	char *max_power = my_strdup("0");
	char *digit = my_strdup("0");
	char *number = my_strdup("0");
	int rev_counter = 0;
	int first_digit = get_first_apearance(str, base);

	while (get_dig(str[first_digit + my_atoi(max_power)], base)[0] != neg)
		max_power = infin_add(max_power, my_strdup("1"));
	while (max_power[0] != neg) {
		digit = get_dig(str[first_digit + rev_counter], base);
		if (digit[0] != neg)
			number = infin_add(number, digit);
		else
			return (number);
		if (compare(max_power, my_strdup("1")) == 1)
			number = infin_mul(number, get_base(base));
		rev_counter++;
		max_power = infin_sub(max_power, my_strdup("1"));
	}
	return ("0");
}
