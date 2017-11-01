##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile parser's functions
##

SRC		=	pf_tree.c	\
			postfix.c	\
			parser.c	\
			parse_neg.c	\
			eval_expr.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-L ../../lib -I../../include

LINKLIB		=	../../lib/

NAMELIB		=	libparser.a

all:		lib

lib:		compile
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

compile:
		gcc -c $(SRC) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(LINKLIB)$(NAMELIB)

re:		fclean	all

debug:		fclean
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
