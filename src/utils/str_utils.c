/*
** EPITECH PROJECT, 2017
** str_utils
** File description:
** Utility functions for manipulatins str
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
	if (*str == 0)
		return (0);
	return (1 + my_strlen(str + 1));
}

char *my_strcat(char *dest, char const *src)
{
	int counter = 0;
	int dest_counter = 0;

	while (dest[dest_counter])
		dest_counter++;
	while (src[counter]) {
		dest[dest_counter + counter] = src[counter];
		counter++;
	}
	dest[dest_counter + counter] = 0;
	return (dest);
}

int is_in(char c, char *str)
{
	int counter = 0;

	while (str[counter]) {
		if (c == str[counter])
			return (counter + 1);
		counter++;
	}
	return (0);
}

int remove_whitespace(char *str)
{
	int counter = 0;
	int offset = 0;

	while (str[counter + offset]) {
		if (str[counter + offset] == ' ')
			offset++;
		str[counter] = str[counter + offset];
		counter++;
	}
	while (str[counter]) {
		str[counter] = 0;
		counter++;
	}
	return (0);
}

char *my_revstr(char *str)
{
	char buffer = 0;
	int size = my_strlen(str) - 1;

	if (str == NULL || str[0] == '\0')
		return (str);
	for (int i = 0; i  <= size / 2; i++){
		buffer = str[i];
		str[i] = str[size - i];
		str[size - i] = buffer;
	}
	return (str);
}
