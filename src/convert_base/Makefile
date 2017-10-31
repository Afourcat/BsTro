##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile parser's functions
##

SRC		=	convert_base.c	\
			get_dec_to_base.c \
			get_base_to_dec.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-L ../../lib -I../../include

LINKLIB		=	../../lib/

NAMELIB		=	libconvert_base.a

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
