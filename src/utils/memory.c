/*
** EPITECH PROJECT, 2017
** memory
** File description:
** Utils functions for memory allocation
*/

void *my_calloc(int size)
{
	void *temp = malloc(size);
	int counter = 0;

	while (counter < size) {
		temp[counter] = 0;
		counter++;
	}
	return (temp);
}
