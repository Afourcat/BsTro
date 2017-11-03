/*
** EPITECH PROJECT, 2017
** mul_alloc.c
** File description:
** alloc_function of mul
*/

#include <stdlib.h>
#include "utils.h"
#include "infin_mul.h"

int get_greatest(char *s1, char *s2)
{
	return (my_strlen(s1) >= my_strlen(s2) ? 1 : 2);
}

char **allocate_buffer(char *s1, char *s2, int size)
{
	int size_buffer = 0;
	char **buffer;
	int i = 0;

	if (my_strlen(s1) >= my_strlen(s2))
		size_buffer = my_strlen(s2);
	else
		size_buffer = my_strlen(s1);
	buffer = my_calloc(sizeof(char *) * (size_buffer + 1));
	buffer[size_buffer] = NULL;
	while (i < size_buffer) {
		buffer[i] = my_calloc(sizeof(char) * (size + i + 2));
		i++;
	}
	return (buffer);
}

void free_all(char **buffer, char *s1, char *s2)
{
	int size_buffer;
	int i = 0;

	if (my_strlen(s1) >= my_strlen(s2))
		size_buffer = my_strlen(s2) + 1;
	else
		size_buffer = my_strlen(s1) + 1;
	while (i < size_buffer) {
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
