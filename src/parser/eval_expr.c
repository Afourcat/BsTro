/*
** EPITECH PROJECT, 2017
** eval_expr.c
** File description:
** useful parsing functions
*/

int number(char **str)
{
	char *temp = *str;
	int res = 0;
	
	while (*temp >= '0' && *temp <= '9') {
		res *= 10;
		res += (*temp - 48);
		temp++;
	}
	*str = temp;
	return (res);
}

int strtol(char *nptr, char **endptr)
{
	char *temp = *str;
	int res = 0;
	
	while (*temp >= '0' && *temp <= '9') {
		res *= 10;
		res += (*temp - 48);
		temp++;
	}
	*endptr = temp;
	return (res);
	
}
