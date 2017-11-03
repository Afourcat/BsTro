#include "infin_add.h"

void my_putstr(char *str) {
	int i = 0;
	while (str[i]) {
		write(1, &str[i++], 1);
	}
}

int main(int argc, char *argv[])
{
	char *res;

	res = infin_add(strdup(argv[1]), strdup(argv[2]));
	//my_putstr(res);
	free(res);
	return (0);
}
