/*
** EPITECH PROJECT, 2017
** pf_tree.c
** File description:
** Binary tree for postfixed expression
*/

#include <stdlib.h>
#include <pf_tree.h>
#include <stack_void.h>

int get_operator(char *str, char *base)
{
	int i = 0;

	if (str[1] != ' ' && str[1] != '\0') {
		return (-1);
	}
	while (base[i]) {
		if (str[0] == base[i]) {
			return (i);
		}
		i++;
	}
	return (-1);
}

char *get_number(char *str)
{
	int size = my_strlen(str);
	int i = 0;
	char *s;

	while (i < size && str[i] != ' ') {
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	for (int j = 0; j < i; j++) {
		s[j] = str[j];
	}
	return (s);
}

ope_t *create_ope(char *str, char *base)
{
	ope_t *ope = malloc(sizeof(ope_t));
	int size = my_strlen(str);
	int operator = get_operator(str, base);

	if (ope == NULL)
		return (NULL);
	if (operator == -1) {
		ope->operator = -1;
		ope->number = get_number2(str);
	} else {
		ope->operator = operator;
		ope->number = NULL;
	}
	ope->left = NULL;
	ope->right = NULL;
	return (ope);
}

ope_t *char_to_ope3(char *str, char *base)
{
	stack_v_t *stack = create_stack_v();
	int i = 0;
	int operator;
	ope_t *tmp;

	while (str[i] != '\0') {
		tmp = create_ope(str + i, base);
		if (tmp->operator != -1) {
			tmp->right = out_stack_v(&stack);
			tmp->left = out_stack_v(&stack);
		} else
			i += my_strlen(tmp->number) - 1;
		add_stack_v(&stack, tmp);
		i += 2;
	}
	return (out_stack_v(&stack));
}
/*
void display_ope(ope_t *ope, char *base)
{
	int i = 0;

	if (ope != NULL) {
		display_ope(ope->left, base);
		if (ope->operator == -1) {
			printf("%s \n", ope->number);
		} else {
			while (ope->operator != i)
				i++;
			printf("OPE : %c\n", base[i]);
		}
		display_ope(ope->right, base);
	}
}

int main(int argc, char *argv[])
{
	char str[] = "2 -42632486432985762398756432986532986532875632985 + 1 3 - *";
	char base[] = "()+-*/%";
	ope_t *ope = char_to_ope3(str, base);
	display_ope(ope, base);
	return (0);
}
*/
