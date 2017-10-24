##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

SRC_DIR		=	$(realpath ./src)

SRC		=	$(SRC_DIR)/stack.c 

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I./include

NAME		=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)

$(OBJ):
	gcc -c $(SRC) $(FLAGS)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
