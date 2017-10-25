##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the add system
##

SRC	=	#mul.c		\
		mul_alloc.c	\
		mul_conv.c

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-I../../../include

LINKLIB	=	../../../lib/

NAMELIB	=	libmul.a

all:	compile	lib

compile:
#	gcc -c $(SRC) $(FLAGS)

lib:
	ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LINKLIB)$(NAMELIB)

re:	clean all
