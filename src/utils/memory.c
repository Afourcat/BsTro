/*
** EPITECH PROJECT, 2017
** memory
** File description:
** Utils functions for memory allocation
*/

#include <stdlib.h>

/**
 * \fn void *my_calloc (int size)
 * \brief Function that malloc size bytes of memory and intializes it at NULL.
 * \param size The size of the allocation.
 * \return A pointer on the first byte of memory allocated.
 */
void *my_calloc(int size)
{
	void *temp = malloc(size);
	int counter = 0;

	while (counter < size) {
		((char*)temp)[counter] = NULL;
		counter++;
	}
	return (temp);
}
