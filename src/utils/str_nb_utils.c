/*
** EPITECH PROJECT, 2017
** str_nb_utils
** File description:
** Functions that helps manipulating string numbers
*/

#include <stdlib.h>
#include <utils.h>

char *get_opposed_number(char *nb)
{
	if (nb[0] == '-')
		nb = my_dup_without_zero(nb, 0);
	else
		nb = my_dup_without_zero(nb, 1);
	return (nb);
}

char *my_allocate(char *str, int bool)
{
	int size = 1;
	int j = 0;
	char *new_str;
	
	while (str[j] == '0' && str[j + 1] != '\0')
		j++;
	while (str[j]) {
		j++;
		size++;
	}
	if (bool == 1)
		size++;
	new_str = malloc(sizeof(char) * size);
	return (new_str);
}

char *my_dup_without_zero(char *str, int bool)
{
	char *new_str = my_allocate(str, bool);
	int i = 0;
	int j = 0;

	if (bool == 1) {
		new_str[0] = '-';
		i = 1;
	}
	while (str[j] == '0' && str[j + 1] != '\0') {
		j++;
	}
	while (str[j]) {
		new_str[i] = str[j];
		i++;
		j++;
	}
	free(str);
	return (new_str);
}

char *remove_minus(char *str)
{
	char *new_str = malloc(sizeof(char) * my_strlen(str));
	int j = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] != '-') {
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j + 1] = '\0';
	return (new_str);
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


