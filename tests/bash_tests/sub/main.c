#include "infin_sub.h"

void my_putstr(char *str) {
	int i = 0;
	while (str[i]) {
		write(1, &str[i++], 1);
	}
}

int main(int argc, char *argv[])
{
	my_putstr(infin_sub(argv[1], argv[2]));
	return (0);
}
