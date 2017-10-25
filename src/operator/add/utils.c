/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** Utils functions
*/

#include <unistd.h>
#include <stdlib.h>

int charToInt(char c)
{
	return (c - '0');
}

char intToChar(int i)
{
	return (i + '0');
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *my_allocate(char *str, int bool)
{
	int size = 1;
	char *new_str;
	
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	while (*str)
		size++;
	if (bool)
		size++;
	new_str = malloc(sizeof(char) * size);
	return (new_str);
}

char *my_dup_without_zero(char *str, int bool)
{
	char *new_str = my_allocate(str, bool);
	int i = 0;

	if (bool) {
		new_str[0] = '-';
		i = 1;
	}
	while (*str == '0' && *(str + 1) != '\0') {
		str++;
		i++;
	}
	while (*str) {
		new_str[i] = *str;
		i++;
		str++;
	}
	free(str);
	return (new_str);
}

int my_strlen(char *str)
{
	int i = 0;

	while (*str) {
		str++;
		i++;
	}
	return (i);
}
