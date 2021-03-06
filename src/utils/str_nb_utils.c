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

char *my_allocate(char *str, int bools, int *counter)
{
	int size = 1;
	int j = 0;
	char *new_str;

	while (str[(*counter)] == '0' && str[(*counter) + 1])
		(*counter)++;
	while (str[(*counter) + j]) {
		j++;
		size++;
	}
	new_str = my_calloc(sizeof(char) * (size + bools));
	return (new_str);
}

char *my_dup_without_zero(char *str, int bools)
{
	int i = 0;
	int j = 0;
	char *new_str = my_allocate(str, bools, &j);
	
	if (bools == 1) {
		new_str[0] = '-';
		i++;
	}
	while (str[j] == '0' && str[j + 1])
		j++;
	while (str[j])
		new_str[i++] = str[j++];
	free(str);
	return (new_str);
}

char *remove_minus(char *str)
{
	char *new_str;
	int j = 0;
	int i = 0;

	if (str[0] == '-')
		new_str = my_calloc(my_strlen(str));
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
	int size_str1 = my_strlen(str1);
	int size_str2 = my_strlen(str2);
	
	if (size_str1 == size_str2) {
		while (str1[i] == str2[i] && i < size_str1)
			i++;
		if (i == size_str1)
			return (0);
		return (str1[i] > str2[i] ? 1 : 2);
	}
	return (size_str1 > size_str2 ? 1 : 2);
}
