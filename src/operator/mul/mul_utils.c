/*
** EPITECH PROJECT, 2017
** mul_utils.c
** File description:
** Utils functions for multiplication
*/

#include "utils.h"

void add_zeros(char *buffer, int nb_zeros, int *iter)
{
	for (int i = 0; i < nb_zeros; i++, (*iter)++)
		buffer[i] = '0';
}

char *add_sign(char *positive, int size)
{
	char *new_re = my_calloc(sizeof(char) * (size + 2));
	int i = 1;
	int j = 0;

	new_re[0] = '-';
	while (positive[j] != '\0')
		new_re[i++] = positive[j++];
	new_re[i] = 0;
	free(positive);
	return (new_re);
}

char **allocate_buffer(int *sizes_nb)
{
	int size_buffer = 0;
	char **buffer;
	int i = 0;
	int size = sizes_nb[0] + sizes_nb[1];

	if (sizes_nb[0] >= sizes_nb[1])
		size_buffer = sizes_nb[1];
	else
		size_buffer = sizes_nb[0];
	buffer = my_calloc(sizeof(char *) * (size_buffer + 1));
	buffer[size_buffer] = NULL;
	while (i < size_buffer)
		buffer[i++] = my_calloc(sizeof(char) * (size + i + 2));
	return (buffer);
}
