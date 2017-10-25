/*
** EPITECH PROJECT, 2017
** infinadd.h
** File description:
** header for infinadd function
*/

#ifndef INFINADD_H_
#define INFINADD_H_

int test_signe(char *str);
int error_test(char *str1, char *str2, int ac);
int test_letter(char *str1);
int test_arg_nbr(int ac);
char *add_it(char *number1, char *number2, char *result_string);
char int_to_char(int i);
int char_to_int(char c);
char *sub_it(char *number1, char *number2, char *result_string, int signe);
int compare(char *bigger, char *lower);

#endif /* INFINADD_H_ */
