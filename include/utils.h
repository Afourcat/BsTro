/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** Header file for utils functions
*/

#ifndef UTILS_H_
#define UTILS_H_

#define CHAR_TO_INT(c) (c - 48)
#define INT_TO_CHAR(i) (i + 48)

#include <stdlib.h>

char *my_revstr(char *str);
void my_putchar(char const c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int my_atoi(char const *str);
char *my_itoa(int nb);
int is_in(char c, char *str);
int remove_whitespace(char *str);
void *my_calloc(size_t size);
char *my_dup_without_zero(char *str, int bools);
char *my_allocate(char *str, int bools, int *counter);
char *remove_minus(char *str);
int compare(char *bigger, char *lower);
char *get_opposed_number(char *nb);
int get_sign(char *nb1, char *nb2);
int put_in_str(char c, char *str);
char *my_alo(char *str, char *operands);
int get_str_nb(char *str, char *to_return, int *i, char *nb_base);
char *my_strdup(char *str);
int compare_base_10(char *nb_base);
int get_pos(char c, char *str);
void replace(char *str, char *out, char *in);
void replace_char_to(char *str, char out, char in);

#endif /* UTILS_H_ */
