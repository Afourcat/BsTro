/*
** EPITECH PROJECT, 2017
** mul_alloc.c
** File description:
** alloc_function of mul
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_mul.h>

char *get_greatest(char *s1, char *s2)
{
	return (my_strlen(s1) >= my_strlen(s2) ? 1 : 2);	
}

char **allocate_buffer(char *s1, char *s2, int size)
{
	int size_buffer;
	char **buffer;
	int i = 0;

	if (get_greatest(s1, s2) == 1)
		size_buffer = my_strlen(s2);
	else
		size_buffer = my_strlen(s1);
	buffer = malloc(sizeof(char*) * (size_buffer + 1));
	buffer[size_buffer] = NULL;
	while (i < size_buffer) {
		buffer[i] = malloc(sizeof(char) * (size + i + 1));
		i++;
	}
	return (buffer);
}

void free_all(char **buffer, char *s1, char *s2)
{
	int size_buffer;
	int i = 0;
	
	
	if (get_greatest(s1, s2) == 1)
		size_buffer = my_strlen(s2) + 1;
	else
		size_buffer = my_strlen(s1) + 1;
	while (i < size_buffer) {
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
