#include "utils.h"

char *postfix(char *str, char *operands, char *base, char *parent);

int main(int ac, char **av)
{
	my_putstr(postfix(av[1], av[2], av[3], av[4]));
	my_putstr("\n");
	return (0);
}
