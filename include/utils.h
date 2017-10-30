/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** Header file for utils functions
*/

#ifndef UTILS_H_
#define UTILS_H_

char *my_revstr(char *str);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int my_atoi(char const *str);
char *my_itoa(int nb);
int is_in(char c, char *str);
int remove_whitespace(char *str);
void *my_calloc(int size);
char *my_dup_without_zero(char *str, int bool);
char *my_allocate(char *str, int bool);
char *remove_minus(char *str);
int compare(char *bigger, char *lower);
int char_to_int(char c);
char int_to_char(int i);
char *get_opposed_number(char *nb);
int get_sign(char *nb1, char *nb2);

#endif /* UTILS_H_ */
