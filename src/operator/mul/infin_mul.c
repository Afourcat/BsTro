/*
** EPITECH PROJECT, 2017
** infin_mul.c
** File description:
** Multiplication operator
*/

static char *mul_wrapper(char *nb1, char *nb2, int bool_s)
{
	
}

char *infin_mul(char *nb1, char *nb2)
{
	int sign_nb1 = get_sign(&nb1);
	int sign_nb2 = get_sign(&nb2);
	int bool_s = 0;

	if (sign_nb1 != sign_nb2 && (sign_nb1 == -1 || sign_nb2 == -1))
		bool_s = 1;
	return (mul_wrapper(nb1, nb2, bool_s));
}
