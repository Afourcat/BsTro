##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

SRC_DIR		=	$(realpath ..)

SRC_UT_DIR	=	$(realpath .)

SRC		=	$(SRC_DIR)/my_strcpy.c #\

SRC_UT		=	$(SRC_UT_DIR)/tests_my_strcpy2.c #\

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage

LDFLAGS		=	-L/usr/local/lib -lcriterion -lgcov

NAME		=	units

all:		$(NAME)


$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

$(OBJ):
		gcc -c $(SRC) $(SRC_UT) $(CDFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
