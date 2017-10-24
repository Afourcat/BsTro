# Must list all project files without the main() function
# Criterion uses its own main() ;
# having a main() in any .c file will have the build fail

SRC_DIR		=	$(realpath ..)
SRC_UT_DIR	=	$(realpath .)

SRC		=	$(SRC_DIR)/add.c #\

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
