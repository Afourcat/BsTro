/*
** EPITECH PROJECT, 2017
** utlis.c
** File description:
** utils for add
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putchar(char c)
{
	write(1, &c, 1);
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

int my_strlen(char const *str)
{
	int i = 0;
	
	while(str[i] != '\0'){
		i++;
	}
	return (i);
}
