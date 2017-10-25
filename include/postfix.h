/*
** EPITECH PROJECT, 2017
** postfix.h
** File description:
** Header file for the postfix parser functions
*/

#ifndef POSTFIX_H_
#define POSTFIX_H_

char *postfix(char *str, char *operands, char *base, char *parent);
char *manage_ope(char c, stack_t **stack, char *operands);
char *manage_parent(char c, stack_t **stack, char *parent);
char *get_str_nbr(char *str);

#endif /* POSTFIX_H_ */
