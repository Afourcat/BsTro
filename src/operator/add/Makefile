##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the add system
##

ROOT		=	$(realpath ../../..)

SRC		=	add_it.c	\
			infinadd.c	\
			sub_it.c	\
			test_add.c	

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I$(ROOT)/include

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	libadd.a

all:		lib

lib:		compile
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

compile:
		gcc -c $(SRC) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(LINKLIB)$(NAMELIB)

re:		clean all

debug:		fclean
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)


