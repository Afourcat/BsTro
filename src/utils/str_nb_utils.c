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

char *my_allocate(char *str, int bools)
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
	new_str = my_calloc(sizeof(char) * (size + bools));
	return (new_str);
}

char *my_dup_without_zero(char *str, int bools)
{
	char *new_str = my_allocate(str, bools);
	int i = 0;
	int j = 0;

	if (bools == 1) {
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
	char *new_str;
	int j = 0;
	int i = 0;
	
	if (str[0] == '-')
		return (str);
	else
		new_str = my_calloc(my_strlen(str) + 1);
	while (str[i] != '\0') {
		if (str[i] != '-') {
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int compare(char *str1, char *str2)
{
	int i = 0;

	if (my_strlen(str2) == my_strlen(str1)) {
		while (str1[i] == str2[i] && i < my_strlen(str1)) {
			i++;
		}
		if (i == my_strlen(str1))
			return (0);
		return (str1[i] > str2[i] ? 1 : 2);
	}
	return (my_strlen(str1) > my_strlen(str2) ? 1 : 2);
}
