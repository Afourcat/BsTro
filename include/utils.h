/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** Header file for utils functions
*/

#ifndef UTILS_H_
#define UTILS_H_

char *my_revstr(char *str);
void my_putchar(char const c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int my_atoi(char const *str);
char *my_itoa(int nb);
int is_in(char c, char *str);
int remove_whitespace(char *str);
void *my_calloc(int size);
char *my_dup_without_zero(char *str, int bools);
char *my_allocate(char *str, int bools);
char *remove_minus(char *str);
int compare(char *bigger, char *lower);
int char_to_int(char c);
char int_to_char(int i);
char *get_opposed_number(char *nb);
int get_sign(char *nb1, char *nb2);
int put_in_str(char c, char *str);
char *my_alo(char *str, char *operands);
int get_str_nb(char *str, char *to_return, int *i, char *nb_base);
char *my_strdup(char *str);


#endif /* UTILS_H_ */
