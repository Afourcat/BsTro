/*
** EPITECH PROJECT, 2017
** postfix.h
** File description:
** Header file for the postfix parser functions
*/

#ifndef POSTFIX_H_
#define POSTFIX_H_

#include "stack.h"

char *postfix(char *str, char *operands, char *base);
char *manage_ope(char c, stack_t **stack, char *operands);
char *manage_parent(char c, stack_t **stack, char *parent);
char *get_str_nbr(char *str);
char *parser(char *str, char *op_base);
char *parse_neg(char *str, char *nb_base, char *op_base);

#endif /* POSTFIX_H_ */
