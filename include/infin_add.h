/*
** EPITECH PROJECT, 2017
** infinadd.h
** File description:
** header for infinadd functions
*/

#ifndef INFIN_ADD_H_
#define INFIN_ADD_H_

int get_sign_ope(char **str);
void add_it(char *nb1, char *nb2, char *res);
int infin_add_wrapped(char **nb1, char **nb2, char *res);
char *infin_add(char *nb1, char *nb2);
void free_sign_ope(char *nb1, char *nb2, int sign_nb1, int sign_nb2);
void sub_it(char *nb1, char *nb2, char *res, int *sizes);
int sub(char *nb1, char *nb2, char *res, int sign);

#endif /* INFIN_ADD_H_ */
