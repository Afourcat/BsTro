/*
** EPITECH PROJECT, 2017
** mul.c
** File description:
** infinite multiplication functions
*/

#include <stdlib.h>
#include <utils.h>
#include <infin_mul.h>

char *infin_mul(char *str1, char *str2)
{
	int bool_s = 0;
	
	if (test_signe(str1) == -1 && test_signe(str2) == -1)
		bool_s = 0;
	else if (test_signe(str1) == -1 || test_signe(str2) == -1)
		bool_s = 1;
	str1 = remove_minus(str1);
	str2 = remove_minus(str2);
	return (post_infin_mul(str1, str2, bool_s));
}

static char  *post_infin_mul(char *str1, char *str2, int bool_s)
{
	int size = my_strlen(str1) + my_strlen(str2);
	char *res = malloc(sizeof(char) * size + 1 + bool_s);
	char **buffer = allocate_buffer(str1, str2, size);
	int greatest = get_greatest(str1, str2);
	
	if (greatest == 1)
		res = mul(str1, str2, buffer, res);
	else
		res = mul(str2, str1, buffer, res);
	if (bool_s == 1)
		res = add_signe(res);
	return (res);
}

char *add_signe(char *str)
{
	char *new_string = malloc(my_strlen(str));
	int i = 1;
	int j = 0;
	
	new_string[0] = '-';
	while (str[j] != '\0') {
		new_string[i++] = str[j++];
	}
	new_string[i + 1] = '\0';
	free(str);
	return (new_string);
}

static int get_signe(char *str1, char *str2)
{
	if (str1[0] == '-' && str2[0] == '-')
		return (0);
	else if (str1[0] != '-' && str2[0] != '-')
		return (0);
	else
		return (1);
}

static int multiply(int a, int b, int *current, int *retain)
{
	int temp_retain = *retain;
	int bool = 0;
	
	*current = a * b;
	if (*current > 9) {
		*retain = *current / 10;		
		*current = ((*current) % 10) + temp_retain;
		bool = 1;
	}
	else {
		*current += *retain;
		*retain = 0;
	}
	return (bool);
}

void add_zeros(char *buffer, int nb_zeros, int *iter)
{
	int size = my_strlen(buffer);
	
	for (int i = size ; i < (size+ nb_zeros); i++) {
		buffer[i] = '0';
		(*iter)++;
	}
}

char *add_all(char *res, char **buffer, int size_l, int size_g)
{
	int counter = 0;
	 
	for (int l = size_l - 1; l >= 0; --l) {
		buffer[l] = my_revstr(buffer[l]);
		res = infin_add(res, buffer[l]);
	}
	return (res);
}

static char *mul(char *greatest, char *lowest, char **buffer, char *res)
{
	int size_g = my_strlen(greatest);
	int size_l = my_strlen(lowest);
	int retain = 0;
	int current_nbr = 0;
	int iter = 0;
	int buffer_nbr = 0;
	int b_l = 0;

	for (int l = size_l - 1; l >= 0 ; l-- , iter = 0, buffer_nbr++) {
	       	add_zeros(buffer[buffer_nbr], buffer_nbr, &iter);
		for (int g = size_g - 1; g >= 0; g--) {
			b_l = multiply(char_to_int(lowest[l])
				       ,char_to_int(greatest[g]), &current_nbr, &retain);
			buffer[buffer_nbr][iter++] = int_to_char(current_nbr);
			if (g == 0 && l == 0 && b_l == 1)
				buffer[buffer_nbr][iter++] = int_to_char(retain);
		}
	}
	res = add_all(res, buffer, size_l, size_g);
	free_all(buffer, greatest, lowest);
	return (res);
}
