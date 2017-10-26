#include <postfix.h>
#include <utils.h>

int main(void)
{
	char *temp = postfix("1-2*7/((8+4-1)*(1-2))", "+-*/", "0123456789", "()");
	my_putstr(temp);
	free(temp);
	return (0);
}
