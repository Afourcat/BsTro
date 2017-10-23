##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

SRC	=	error_utlis.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bistro-matic

all:

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
