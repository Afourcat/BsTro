/*
** EPITECH PROJECT, 2017
** replace.c
** File description:
** Function that replace char in a string
*/

#include "utils.h"

int compare_base_10(char *nb_base)
{
	int size = my_strlen(nb_base);
	char base_10[] = "0123456789";

	if (size != 10)
		return (-1);
	for (int i = 0; i < size; i++)
		if (nb_base[i] != base_10[i])
			return (0);
	return (1);
}

int get_pos(char c, char *str)
{
	int i = 0;
	
	while (str[i] && c != str[i])
		i++;
	if (i == my_strlen(str))
		return (-1);
	return (i);
}

void replace(char *str, char *out, char *in)
{
	int size = my_strlen(str);
	int pos;
	
	for (int i = 0; i < size; i++) {
		pos = get_pos(str[i], out);
		if (pos != -1)
			str[i] = in[pos];
	}
}

void replace_char_to(char *str, char out, char in)
{
	int size = my_strlen(str);

	for (int i = 0; i < size; i++)
		if (str[i] == out)
			str[i] = in;
}
