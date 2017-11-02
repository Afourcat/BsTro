/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Function that allocates memory and copies the string given as argument in it.
*/

#include "utils.h"

char *my_strdup(char *src)
{
	char *dest;
	int counter = 0;

	dest = my_calloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[counter]) {
		dest[counter] = src[counter];
		counter++;
	}
	return (dest);
}
