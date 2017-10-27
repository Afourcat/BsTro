/*
** EPITECH PROJECT, 2017
** infin_mul.h
** File description:
** header file of infin_mul functions
*/

#ifndef INFIN_MUL_H_
#define INFINE_MUL_H

static int multiply(int a, int b, int *current, int *retain);
char *infin_mul(char *str1, char *str2);
static char *mul(char *greatest, char *lowest, char **buffer, char *res);
static char  *post_infin_mul(char *str1, char *str2, int bool_s);
char *add_signe(char *str);
static int get_signe(char *str1, char *str2);
void add_zeros(char *buffer, int nb_zeros, int *iter);
char *add_all(char *res, char **buffer, int size_l, int size_g);
char *get_greatest(char *s1, char *s2);
char **allocate_buffer(char *s1, char *s2, int size);
void free_all(char **buffer, char *s1, char *s2);

#endif /* INFIN_MUL_H */
