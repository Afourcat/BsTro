/*
** EPITECH PROJECT, 2017
** infinadd.c
** File description:
** infinite addition with two arg
*/

#include <stdlib.h>
#include <infinadd.h>

char *infin_add(char *nb1, char *nb2)
{
	int size = (my_strlen(nb1) > my_strlen(nb2) ?
		    my_strlen(nb1) : my_strlen(nb2));
	char *result_string = malloc(sizeof(char) * size + 2);
	int bool = 0;
	
	bool = inf_add(nb1, nb2, size, result_string);
	my_revstr(result_string);
	return (my_dup_without_zero(result_string, bool));
}

int inf_add(char *nb1, char *nb2, int size, char *result_string)
{
        int signe_1 = test_signe(nb1);
	int signe_2 = test_signe(nb2);
	int bool_s = 0;
	
	nb1 = remove_minus(nb1);
	nb2 = remove_minus(nb2);
	if (signe_1 == -1 && signe_2 == -1) {
		add_it(nb1, nb2, result_string);
		if (nb1[0] != '0' && nb2[0] != '0')
			bool_s = 1;
	}
	else if (signe_1 == -1 || signe_2 == -1) {
		if (compare(nb1, nb2) == 1)
			bool_s = sub_it(nb1, nb2, result_string, signe_1);
		else
			bool_s = sub_it(nb2, nb1, result_string, signe_2);
	}
	else
		add_it(nb1, nb2, result_string);
	return (bool_s);
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
	new_str[j + 1] == '\0';
	return (new_str);
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
	return (new_str);
}
