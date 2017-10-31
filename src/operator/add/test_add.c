/*
** EPITECH PROJECT, 2017
** test_add.c
** File description:
** test function for inifinite add
*/

#include <unistd.h>
#include "utils.h"

int test_signe(char *str)
{
	int i = 1;

	if (str[0] == '-')
		return (-1);
	while(str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == '-') {
			return (-1);
		}
		else if (str[i] >= '0' && str[i] <= '9' && str[i - 1] != '-') {
			return (1);
		}
		i++;
	}
	return (0);
}

void size_post(int *size1, int *size2)
{
	(*size1)--;
	(*size2)--;
}

static int ctoi(char a)
{
	char_to_int(a);
}

static char itoc(int i)
{
	int_to_char(i);
}

void subsub(char **s, int bi_s, int low_s, int cr_nb)
{
	int tab[2] = {0, 0};
	
	while (bi_s >= 0 || low_s >= 0) {
	       	if (low_s < 0)
			cr_nb = ctoi(s[0][bi_s]) - tab[0];
		else {
			cr_nb = ctoi(s[0][bi_s]) - ctoi(s[1][low_s]) - tab[0];
		}
		if (cr_nb < 0) {
			cr_nb = ctoi(s[0][bi_s]) + 10;
			cr_nb -= (low_s < 0 ? 1 : ctoi(s[1][low_s]) + tab[0]);
			tab[0] = 1;
		}
		else
			tab[0] = 0;
		s[2][tab[1]] = itoc(cr_nb);
		tab[1]++;
		size_post(&bi_s, &low_s);
	}
}
