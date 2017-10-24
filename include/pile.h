/*
** EPITECH PROJECT, 2017
** pile.h
** File description:
** filo
*/

#ifndef PILE_H_
#define PILE_H_

typedef struct pile
{
	char data;
	struct pile *ptr;
} pile_t;

pile_t *create_pile(char data);
pile_t *add_pile(pile_t **pile, char data);
char out_pile(pile_t **pile);

#endif /* PILE_H_ */
