/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** Header file for utils functions
*/

#ifndef UTILS_H_
#define UTILS_H_

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int my_atoi(char const *str);
int is_in(char c, char *str);
int remove_whitespace(char *str);
void *my_calloc(int size);

#endif /* UTILS_H_ */
