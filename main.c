#include <postfix.h>
#include <utils.h>

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *temp = postfix(av[1], "+-*/", "0123456789", "()");
	int counter = 0;
	
	my_putstr(temp);
	free(temp);
	return (0);
}
