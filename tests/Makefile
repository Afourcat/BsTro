##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

SRC_DIR		=	$(realpath ../src)

SRC_UT_DIR	=	$(realpath .)

SRC		=	$(SRC_DIR)/ 		

SRC_UT		=	$(SRC_UT_DIR)/

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-I../include -Wall -Wextra --coverage -w

LDFLAGS		=	-L/usr/local/lib -lcriterion -lgcov

NAME		=	units

all:		$(NAME)


$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

#$(OBJ):
#		gcc -c $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS) $(INCL)

#add:
#		gcc -o add $(SRC_UT_DIR)/tests_add.c $(wildcard $(SRC_DIR)/operator/add/*.c) $(CFLAGS) $(LDFLAGS)


clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -f add

re:		fclean all
