/*
** EPITECH PROJECT, 2017
** strin_nb_utils_2.c
** File description:
** Second file containing all functions relatives to manipulating string numbers
*/

int get_sign(char *str1, char *str2)
{
	if (str1[0] == '-' && str2[0] == '-')
		return (0);
	else if (str1[0] != '-' && str2[0] != '-')
		return (0);
	else
		return (1);
}
