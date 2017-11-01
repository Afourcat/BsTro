/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
** Return the number in a string
*/

static int getnbr_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

static int get_signe(char const *str, int *pos)
{
	int signe = 1;

	while (!getnbr_isnum(str[*pos])) {
		if (str[*pos] == '-')
			signe *= -1;
		(*pos)++;
	}
	return (signe);
}

static int check_valid_str(char const *str)
{
	int i = 0;

	while (!getnbr_isnum(str[i])) {
		if (str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

/**
 * \fn my_atoi (char const *str)
 * \brief Function that converts an string into an integer.
 * \param str The string to be converted.
 * \return The integer converted from the string.
 */
int my_atoi(char const *str)
{
	int i = 0;
	int nbr = 1;

	if (check_valid_str(str))
		return (0);
	nbr *= get_signe(str, &i);
	nbr *= str[i] - '0';
	i++;
	while (getnbr_isnum(str[i])) {
		nbr *= 10;
		if (nbr >= 0)
			nbr += (str[i] - '0');
		else
			nbr -= (str[i] - '0');
		i++;
	}
	return (nbr);
}
