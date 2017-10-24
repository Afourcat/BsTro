/*
** EPITECH PROJECT, 2017
** mul_alloc.c
** File description:
** alloc_function of mul
*/

#include <stdlib.h>
#include <utils.h>


char *get_greatest(char *s1, char *s2)
{
	return (my_strlen(s1) >= my_strlen(s2) ? s1 : s2);	
}

char *get_lowest(char *s1, char *s2)
{
	return (my_strlen(s1) <= my_strlen(s2) ? s1 : s2);	
}

char **allocate_buffer(char *s1, char *s2, int size)
{
	int size_buffer = my_strlen(get_lowest(s1, s2)) + 1;
	char **buffer = malloc(sizeof(char*) * size_buffer);
	int i = 0;

	buffer[size_buffer - 1] = NULL;
	while (i < size_buffer) {
		buffer[i] = malloc(sizeof(char) * size);
		i++;
	}
	return (buffer);
}

void free_all(char **buffer, char *s1, char *s2)
{
	int size_buffer = my_strlen(get_lowest(s1, s2)) + 1;
	int i = 0;

	while (i < size_buffer) {
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
