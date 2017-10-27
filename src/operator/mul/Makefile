##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the mul system
##

ROOT		=	$(realpath ../../..)

SRC		=	infin_mul.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I$(ROOT)/include

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	libmul.a

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
