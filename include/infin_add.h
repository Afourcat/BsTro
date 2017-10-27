/*
** EPITECH PROJECT, 2017
** infinadd.h
** File description:
** header for infinadd function
*/

#ifndef INFIN_ADD_H_
#define INFIN_ADD_H_

int test_signe(char *str);
int error_test(char *str1, char *str2, int ac);
void add_it(char *number1, char *number2, char *result_string);
char int_to_char(int i);
int char_to_int(char c);
int sub_it(char *number1, char *number2, char *result_string, int signe);
int compare(char *bigger, char *lower);
char *remove_minus(char *str1);
char *my_allocate(char *str, int sign);
char *my_dup_without_zero(char *str, int sign);
int inf_add(char *nb1, char *nb2, int size, char *result_string);
char *infin_add(char *nb1, char *nb2);

#endif /* INFIN_ADD_H_ */
