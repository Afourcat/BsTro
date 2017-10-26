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

	for (int i = 0; i  <= size / 2; i++){
		buffer = str[i];
		str[i] = str[size - i];
		str[size - i] = buffer;
	}
	return (str);
}
