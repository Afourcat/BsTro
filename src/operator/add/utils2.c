/*
** EPITECH PROJECT, 2017
** utils2.c
** File description:
** Utils functions 2
*/

#include <stdlib.h>
#include <infin_add.h>

char *get_buffer(int size)
{
	char *buffer = malloc(sizeof(char) * (size + 2));

	return (buffer);
}

char *my_revstr(char *str)
{
	int size = my_strlen(str);
	int i = 0;
	char tmp;

	while (i < size / 2) {
		tmp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = tmp;
		i++;
	}
	return (str);
}

void my_swap_int(int *n1, int *n2)
{
	int tmp;
	
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void my_swap_char(char **c1, char **c2)
{
	char *tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int bool_signe(char **first_nb, char **second_nb, int *signe_f, int *signe_s)
{
	if (*signe_f == *signe_s && *signe_f == -1)
		return(1);
	else {
		if (my_strcmp(*first_nb, *second_nb) < 0) {
			my_swap_char(first_nb, second_nb);
			my_swap_int(signe_f, signe_s);
		}
		if (*signe_f == -1 && my_strcmp(*first_nb, *second_nb) > 0)
			return (1);
	}
	return (0);
}
