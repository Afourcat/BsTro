/*
** EPITECH PROJECT, 2017
** infin_mul.h
** File description:
** header file of infin_mul functions
*/

#ifndef INFIN_MUL_H_
#define INFINE_MUL_H

char *infin_mul(char *str1, char *str2, char *op_base);
char *add_signe(char *positive);
void add_zeros(char *buffer, int nb_zeros, int *iter);
char *add_all(char **res, char **buffer, int size_l, char *op_base);
int get_greatest(char *s1, char *s2);
char **allocate_buffer(char *s1, char *s2, int size);
void free_all(char **buffer, char *s1, char *s2);

#endif /* INFIN_MUL_H */
