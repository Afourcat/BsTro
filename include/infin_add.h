/*
** EPITECH PROJECT, 2017
** infinadd.h
** File description:
** header for infinadd functions
*/

#ifndef INFIN_ADD_H_
#define INFIN_ADD_H_

int get_sign_add(char **str, char *op_base);
void add_it(char *nb1, char *nb2, char *res);
int infin_add_wrapped(char **nb1, char **nb2, char *res, char *op_base);
char *infin_add(char *nb1, char *nb2, char *op_base);
void sub_it(char *nb1, char *nb2, char *res, int *sizes);
int sub(char *nb1, char *nb2, char *res, int sign);

/*int test_signe(char *str);
void add_it(char *number1, char *number2, char *result_string);
int sub_it(char *number1, char *number2, char *result_string, int signe);
int inf_add(char *nb1, char *nb2, int size, char *result_string);
char *infin_add(char *nb1, char *nb2);
void subsub(char **strs, int bigger_size, int lower_size, int current_nbr);
void size_post(int *size1, int *size2);*/

#endif /* INFIN_ADD_H_ */
