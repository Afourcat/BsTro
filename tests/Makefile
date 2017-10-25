##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

SRC_DIR		=	$(realpath ../src)

SRC_UT_DIR	=	$(realpath .)

SRC		=	$(SRC_DIR)/stack_void.c 		\
			$(SRC_DIR)/operator/add/$(wildcard *.c)	

SRC_UT		=	$(SRC_UT_DIR)/tests_stack_void.c	\
			$(SRC_UT_DIR)/tests_add.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-I../include -Wall -Wextra --coverage -g

LDFLAGS		=	-L/usr/local/lib -lcriterion -lgcov

NAME		=	units

all:		$(NAME)


$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

#$(OBJ):
#		gcc -c $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS) $(INCL)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
