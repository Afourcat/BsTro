##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the sub system
##

SRC		=	

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I../../../include

LINKLIB		=	../../../lib/

NAMELIB		=	libsub.a

all:		compile	lib

compile:
#		gcc -c $(SRC) $(FLAGS)

lib:
#		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(LINKLIB)$(NAMELIB)

re:		clean all

debug:
		gcc -c $(SRC) $(FLAGS) -g
		ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
