#include <postfix.h>
#include <utils.h>

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *temp = postfix("1-2*7/((8+4-1)*(1-2))", "+-*/", "0123456789", "()");
	int counter = 0;
	
	while (temp[counter]) {
		printf("%d ", temp[counter]); 
		counter++;
	}
	my_putchar('\n');
	my_putstr(temp);
	free(temp);
	return (0);
}
