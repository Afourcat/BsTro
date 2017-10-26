#include <postfix.h>
#include <utils.h>

int main(void)
{
	my_putstr(postfix("(1+2)*3", "+-*/", "0123456789", "()"));
	my_putstr("\n");
	my_putstr(postfix("1-2*7/((8+4-1)*(1-2))", "+-*/", "0123456789", "()"));
}
