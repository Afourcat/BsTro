/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** Compare two strings.
*/

int check2(char s1, char s2)
{
	return (s1 == s2) ? (0) : (s1 - s2);
}

int get_size(char const *s1, char const *s2)
{
	int size_s1 = 0;
	int size_s2 = 0;

	while (s1[size_s1])
		size_s1 = size_s1 + 1;
	while (s2[size_s2])
		size_s2 = size_s2 + 1;
	return (size_s1 > size_s2) ? (size_s1) : (size_s2);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int res = 0;

	while (i < get_size(s1, s2)) {
		res = check2(s1[i], s2[i]);
		if (res != 0)
			return (res);
		i = i + 1;
	}
	return (res);
}
