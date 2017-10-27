##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the pow system
##

ROOT		=	$(realpath ../../..)

SRC		=	infin_pow.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I$(ROOT)/include

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	libpow.a

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

debug:		fclean
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
