/*
** EPITECH PROJECT, 2017
** infin_mul.h
** File description:
** header file of infin_mul functions
*/

#ifndef INFIN_MUL_H_
#define INFINE_MUL_H

char *mul(char *str1, char *str2);
int char_to_int(char c);
char int_to_char(int i);
char *get_greatest(char *s1, char *s2);
char *get_lowest(char *s1, char *s2);
char **allocate_buffer(char *s1, char *s2, int size);
void free_all(char **buffer, char *s1, char *s2);

#endif /* INFIN_MUL_H */
