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
	char *res = my_calloc(sizeof(char) * (size + 1));
	while (size != 0) {
		res[size] = nb_base[*((int *)out_stack_v(&stack))];
		size--;
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
	int current = 0;
	
	do {
		div = infin_div(str, my_itoa(s_base));
		mod = infin_sub(str, infin_mul(my_strdup(div), my_itoa(s_base))); 
		str = div;
		current = my_atoi(mod); 
		add_stack_v(&stack, &current);
		free(mod);
		i++;
	} while (div != 0);
	free(div);
	free(str);
	return (create_res(stack, nb_base,i));
}

int main(int argc, char *argv[])
{
	char *res;
	res = convert_base(my_strdup(argv[1]), my_strdup("0123456789ABCDEF"), 1);
	printf("%s\n", res);
	return (0);
}
