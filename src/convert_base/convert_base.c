/*
** EPITECH PROJECT, 2017
** convert_base.c
** File description:
** convert base to another base
*/

#include "utils.h"
#include "stack_void.h"
#include "infin_sub.h"
#include "infin_add.h"
#include "infin_mul.h"
#include "infin_div.h"
#include "convert_base.h"

char *create_res(stack_v_t *stack, char *nb_base, int size)
{
	char *temp;
	char *res = my_calloc(sizeof(char) * (size + 2));
	int i = 0;

	if (!is_in(((char *)stack->data)[0], nb_base))
		res[i++] = *((char *)out_stack_v(&stack));
	while (i < size) {
		temp = (char *)out_stack_v(&stack);
		res[i] = nb_base[my_atoi(temp)];
		i++;
		free(temp);
	}
	free(stack);
	return (res);
}

char *deci_to_base(char *str, char *nb_base, char neg)
{
	int i = 0;
	int s_base = my_strlen(nb_base);
	char *div = NULL;
	char *mod;
	stack_v_t *stack = create_stack_v();

       	do {
		if (div != NULL)
			free(div);
		div = infin_div(my_strdup(str), my_itoa(s_base));
		mod = infin_sub(str, infin_mul(my_strdup(div), my_itoa(s_base))); 
		free(str);
		str = my_strdup(div);
		add_stack_v(&stack, my_strdup(mod));
		free(mod);
		i++;
	} while (div[0] != '0');
	if (str[0] == '-')
		add_stack_v(&stack, my_strdup(&neg));
       	free(div);
	free(str);
	return (create_res(stack, nb_base,i));
}

static int get_pos(char c, char *str)
{
	int i = 0;
	
	while (str[i] && c != str[i])
		i++;
	return (i);
}

char *base_to_dec(char *str, char *nb_base, char neg)
{
	int i = 1;
	int size = my_strlen(str);
	char *s_nb_base = my_itoa(my_strlen(nb_base));
	char *res = my_itoa(get_pos(str[0], nb_base));
	char *tmp;
	
	while (i < size  && size > 1) {
		tmp = my_itoa(get_pos(str[i], nb_base));
		res = infin_mul(res, my_strdup(s_nb_base));
		res = infin_add(res, my_strdup(tmp));
		i++;
		free(tmp);
	}
	free(s_nb_base);
	free(str);
	return (res);
}

char *convert_base(char *str, char *nb_base, char neg, int bool)
{
	if (!bool)
		return (base_to_dec(str, nb_base, neg));
	return(deci_to_base(str, nb_base, neg));
}
