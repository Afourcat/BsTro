/*
** EPITECH PROJECT, 2017
** my_getnbr_base
** File description:
** Function that converts and returns a number in a
** given base into decimal number
*/

#include "utils.h"
#include "infin_add.h"
#include "infin_sub.h"
#include "infin_mul.h"
#include "infin_div.h"

char *get_dig(char symbol, char const *base)
{
	int counter = 0;

	while (base[counter] != symbol)
		counter++;
	if (base[counter])
		return (my_atoi(counter));
	else
		return ("-1");
}

char *get_base(char const *base)
{
	int counter = 0;

	while (base[counter])
		counter++;
	return (my_atoi(counter));
}

int get_first_apearance(char const *str, char const *base)
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

char *get_sign_or_null(char const *str, int first_digit, char *number)
{
	if (str[first_digit - 1] == '-')
		return (my_dup_without_zero(number, 1));
	else
		return (number);
}

char *getnbr_base(char const *str, char const *base)
{
	char *max_power;
	char *digit;
	char *number = 0;
	int rev_counter = 0;
	int first_digit = get_first_apearance(str, base);

	while (compare(get_dig(str[first_digit + max_power], base), "0") <= 1)
		max_power = infin_add(max_power, "1");
	while (compare(max_power, "0") <= 1) {
		digit = get_dig(str[first_digit + rev_counter], base);
		if (compare(digit, "0") <= 1)
			number = infin_add(number, digit);
		else
			return (get_sign_or_null(str, first_digit, number));
		if (compare(max_power, "1") == 1)
			number = infin_mul(number, get_base(base));
		rev_counter++;
		max_power = infin_sub(max_power, "1");;
	}
	return ("0");
}
