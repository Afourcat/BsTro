/*
** EPITECH PROJECT, 2017
** str_nb_utils.c
** File description:
** 3th utils file
*/

int get_str_nb(char *str, char *to_return, int *i)
{
	int size = my_strlen(to_return);

	while (str[*i] <= '9' && str[*i] >= '0') {
		to_return[size] = str[*i];
		size++;
		(*i)++;
	}
	(*i)--;
	to_return[size] = ' ';
	return (0);
}

char *my_alo(char *str, char *operands)
{
	char *to_return;
	int counter = 0;
	int size_counter = 0;

	while (str[counter]) {
		if (!(str[counter] == operands[0] ||
		      str[counter] == operands[1]))
			size_counter++;
		counter++;
	}
	to_return = my_calloc(size_counter * 2);
	return (to_return);
}
