/*
** EPITECH PROJECT, 2017
** infin_mul.h
** File description:
** header file of infin_mul functions
*/

#ifndef INFIN_MUL_H_
#define INFINE_MUL_H

char *infin_mul(char *str1, char *str2);
char *add_sign(char *positive, int size);
void add_zeros(char *buffer, int nb_zeros, int *iter);
char **allocate_buffer(int *sizes_nb);
void free_all(char **buffer, int size_buffer);

#endif /* INFIN_MUL_H */
