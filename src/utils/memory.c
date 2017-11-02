/*
** EPITECH PROJECT, 2017
** memory
** File description:
** Utils functions for memory allocation
*/

#include <stdlib.h>

void *my_calloc(size_t size)
{
	void *temp = malloc(size);
	int counter = 0;

	while (counter < size) {
		((char*)temp)[counter] = 0;
		counter++;
	}
	return (temp);
}
