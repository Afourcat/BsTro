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

char *convert_base(char *str, char *nb_base, int bool)
{
	return(deci_to_base(str, nb_base));
}

char *create_res(stack_v_t *stack, char *nb_base, int size)
{
	char *temp;
	char *res = my_calloc(sizeof(char) * (size + 1));
	int i = 0;

	while (i < size) {
		temp = (char *)out_stack_v(&stack);
		res[i] = nb_base[my_atoi(temp)];
		i++;
		free(temp);
	}
	return (res);
}

deci_to_base(char *str, char *nb_base)
{
	int i = 0;
	int s_base = my_strlen(nb_base);
	char *div;
	char *mod;
	stack_v_t *stack = create_stack_v();
	
	do {
		div = infin_div(my_strdup(str), my_itoa(s_base));
		mod = infin_sub(str, infin_mul(my_strdup(div), my_itoa(s_base))); 
		str = my_strdup(div);
		add_stack_v(&stack, my_strdup(mod));
		free(mod);
		i++;
	} while (div[0] != '0');
	free(div);
	return (create_res(stack, nb_base,i));
}
