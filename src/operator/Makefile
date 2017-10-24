##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for operator
##

SRC	=	$(SRC)

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-I./../../include/ 

NAME	=	operator

all:

$(OBJ):
	gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
