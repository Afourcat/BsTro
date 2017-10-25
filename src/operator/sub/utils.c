/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** Utils functions
*/

#include <unistd.h>

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

void my_putstr(char *str)
{
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	while (*str)
		my_putchar(*str++);
	my_putchar('\n');
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
