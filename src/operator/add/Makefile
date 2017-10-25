##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the add system
##

SRC		=	add.c		\
			error.c		\
			my_strcmp.c	\
			utils.c		\
			utils2.c	\
			str_utils.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I../../../include

LINKLIB		=	../../../lib/

NAMELIB		=	libadd.a

all:		compile	lib

compile:
		gcc -c $(SRC) $(FLAGS)

lib:
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(LINKLIB)$(NAMELIB)

re:		clean all

debug:
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)


