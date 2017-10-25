/*
** EPITECH PROJECT, 2017
** infin_add.h
** File description:
** Header file of infinadd project
*/

#ifndef INFIN_ADD_H_
#define INFIN_ADD_H_

char *inf_add(char *first, char *second);
char *get_buffer(int size);
int calc(int nb1, int nb2, int *retain);
int calc_neg(int nb1, int nb2, int *retain);
char *my_revstr(char *str);
int get_signe(char *str);
char *update(char *str, int signe, int *size);
char *add_zeros(char *str, int size);
void init(char **str1, char **str2, int *signe1, int *signe2);
void my_swap_int(int *n1, int *n2);
void my_swap_char(char **c1, char **c2);
void print_signe(char **first_nbr, char **second_nbr, int *signe_f, int *signe_s);
int charToInt(char c);
char intToChar(int i);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
int get_size(char const *s1, char const *s2);
int check2(char s1, char s2);
void my_putchar_error(char c);
void my_putstr_error(char *str);
int is_only_num(char *str);
int check(int argc, char **argv);

#endif /* INFIN_ADD_H_ */
