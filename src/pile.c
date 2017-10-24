/*
** EPITECH PROJECT, 2017
** pile.c
** File description:
** pile first in first out 
*/

#include <../include/pile.h>
#include <stdlib.h>

pile_t *create_pile(char data)
{
	pile_t *new_pile = malloc(sizeof(pile_t));

	new_pile->data = data;
	new_pile->ptr = NULL;
	return (new_pile);
}

pile_t *add_pile(pile_t **pile, char data)
{
	pile_t *new_pile = malloc(sizeof(pile_t));

	new_pile->data = data;
	new_pile->ptr = *pile;
	*pile = new_pile;
	return (*pile);
}

char out_pile(pile_t **pile)
{
	pile_t *temp = *pile;
	char data = temp->data;
	
	*pile = temp->ptr;
	free(temp);
	return (data);
}
