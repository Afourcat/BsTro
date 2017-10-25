/*
** EPITECH PROJECT, 2017
** mul.c
** File description:
** infinite multiplication functions
*/

#include <stdlib.h>
#include <utils.h>

char *mul(char *str1, char *str2)
{
	int size = my_strlen(str1) + my_strlen(str2);
	char *res = malloc(sizeof(char) * size);
	char **buffer = allocate_buffer(str1, str2, size);
	char *greatest = get_greatest(str1, str2);
	char *lowest = get_lowest(str1, str2);
	
	return(infin_mul(greatest, lowest, buffer, res));
}

static void multiply(int a, int b, int *current, int *retain)
{
	int temp_retain = *retain;
	
	*current = a * b;
	if (*current > 9) {
		*retain = *current / 10;		
		*current = ((*current) % 10) + temp_retain;
	}
	else {
		*current += *retain;
		*retain = 0;
	}
}

void add_zeros(char **buffer)
{
	int nb_zeros = 0;
	int counter = 0;
	int counter2 = 0;

	while (buffer[counter][0] != 0)
		counter++;
	nb_zeros = my_strlen(buffer[counter - 2]) - my_strlen(buffer[counter - 1]);
	counter2 = my_strlen(buffer[counter - 1]) - 1;
	while (nb_zeros > 0) {
		buffer[counter - 1][counter2] = '0';
		nb_zeros--;
		counter2++;
	}
}

char *add_all(char *res, char **buffer, int size_l, int size_g)
{
	int counter = 0;

	for (int l = size_l; l > 0; --l) {
		res = infin_add(res, buffer[l]);
	}
	return (res);
}

static char *infin_mul(char *greatest, char *lowest, char **buffer, char *res)
{
	int size_g = my_strlen(greatest);
	int size_l = my_strlen(lowest);
	int retain = 0;
	int current_nbr = 0;
	int iter = 0;
	
	for (int l = size_l - 1; l > 0 ; l--) {
		iter = 0;
		for (int g = size_g - 1; g > 0; g--) {
			multiply(lowest[l], greatest[g], &current_nbr, &retain);
			buffer[l][iter] = int_to_char(current_nbr);
			iter++;
		}
	}
	res = add_all(buffer, lowest, greatest);
	free_all(buffer, greatest, lowest);
	return (res);
}
