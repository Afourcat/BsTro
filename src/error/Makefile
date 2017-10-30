##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile utils functions
##

ROOT		=	$(realpath ../..)

SRC		=	error_display.c

OBJ		=	$(SRC:.c=.o)

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	liberror.a

FLAGS		=	-I$(ROOT)/include


all:		compile	lib

compile:
		gcc -c $(SRC) $(FLAGS)

lib:
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(LINKLIB)$(NAMELIB)

re:		fclean	all

debug:		fclean
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
