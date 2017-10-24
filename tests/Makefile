##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

SRC_DIR		=	$(realpath ../src)

SRC_UT_DIR	=	$(realpath .)

SRC		=	$(SRC_DIR)/stack.c \
			$(SRC_DIR)/operator/add/add.c 

SRC_UT		=	$(SRC_UT_DIR)/tests_stack.c \
			$(SRC_UT_DIR)/tests_add.c 

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage

LDFLAGS		=	-L/usr/local/lib -lcriterion -lgcov

INCL		=	-I../include

NAME		=	units

all:		$(NAME)


$(NAME):	$(OBJ)
		gcc  $(INCL) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
