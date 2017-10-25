##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile parser's functions
##

SRC		=	pf_tree.c	\
			postfix.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-L ../../lib -I../../include

LINKLIB		=	../../lib/

NAMELIB		=	libparser.a

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

debug:
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
