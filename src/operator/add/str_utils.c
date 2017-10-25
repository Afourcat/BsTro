/*
** EPITECH PROJECT, 2017
** str_utils.c
** File description:
** Str utils
*/

#include <stdlib.h>
#include <infin_add.h>

int get_signe(char *str)
{
	return ((*str == '-') ? -1 : 1);
}

char *update(char *str, int signe, int *size)
{
	str = (signe == -1) ? str + 1 : str;
	*size = my_strlen(str) - 1;
	return (str);
}

char *add_zeros(char *str, int size)
{
	int size_str = my_strlen(str);
	char *res = malloc(sizeof(char) * (size + 1));
	int i = 0;

	if (size_str >= size) {
		return (str);
	}
	while (i < size - size_str) {
		res[i] = '0';
		i++;
	}
	while (i < size) {
		res[i] = str[i - (size - size_str)];
		i++;
	}
	return (res);
}
