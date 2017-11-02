/*
** EPITECH PROJECT, 2017
** calc.h
** File description:
** Constant for the calc_engine
*/

#ifndef CALC_H_
#define CALC_H_

char *my_add(char *nb1, char *nb2, char *op_base);
char *my_sub(char *nb1, char *nb2, char *op_base);
char *my_mul(char *nb1, char *nb2, char *op_base);
char *my_div(char *nb1, char *nb2, char *op_base);
char *my_mod(char *nb1, char *nb2, char *op_base);

char * const (*OPERATORS[])(char *, char *, char *) = {&my_add,
						&my_sub,
						&my_mul,
						&my_div,
						&my_mod};

#endif /* CALC_H_ */
