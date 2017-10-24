/*
** EPITECH PROJECT, 2017
** str_utils
** File description:
** Utility functions for manipulatins str
*/

int my_strlen(char const *str)
{
	int counter = 0;

	while(str[counter]) {
		counter++;
	}
	return (counter);
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
	return (dest);	
}
