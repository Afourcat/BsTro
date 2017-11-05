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

char *create_res(stack_v_t *stack, char *nb_base, int size, int neg)
{
	char *temp;
	char *res = my_calloc(sizeof(char) * (size + 2));
	int i = 0;

	if (((char *)stack->data)[0] == neg)
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

char *deci_to_base(char *str, char *nb_base, char neg, int bool_s)
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
		mod = infin_sub(my_strdup(str), infin_mul(my_strdup(div), my_itoa(s_base)));
		(bool_s && !i) ? free(str - 1) : free(str);
		str = my_strdup(div);
		add_stack_v(&stack, my_strdup(mod));
		free(mod);
		i++;
	} while (div[0] != '0');
	if (str[0] == '-')
		add_stack_v(&stack, my_strdup(&neg));
	free(str);
       	free(div);
	return (create_res(stack, nb_base, i, neg));
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
	int i = 0;
	int size = my_strlen(str);
	char *s_nb_base = my_itoa(my_strlen(nb_base));
	char *res;
	char *tmp;
	int bool_s = (str[i] == neg) ? 1 : 0;

	if (bool_s)
		i++;
	res = my_itoa(get_pos(str[i++], nb_base));
	while (i < size  && size > 1) {
		tmp = my_itoa(get_pos(str[i], nb_base));
		res = infin_mul(res, my_strdup(s_nb_base));
		res = infin_add(res, my_strdup(tmp));
		i++;
		free(tmp);
	}
	if (bool_s)
		res = my_dup_without_zero(res, 1);
	free(s_nb_base);
	free(str);
	return (res);
}

char *convert_base(char *str, char *nb_base, char neg, int bool)
{
	int bool_s = 0;
	char *res;
	
	if (!bool)
		return (base_to_dec(str, nb_base, neg));
	if (str[0] == neg) {
		str++;
		bool_s = 1;
	}
	res = deci_to_base(str, nb_base, neg, bool_s);
	return(my_dup_without_zero(res, bool_s));
}
