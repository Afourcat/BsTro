##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile utils functions
##

ROOT	=	$(realpath ../..)

SRC	=	display.c	\
		my_atoi.c	\
		stack.c		\
		stack_void.c	\
		str_utils.c

OBJ	=	$(SRC:.c=.o)

LINKLIB	=	$(ROOT)/lib/

NAMELIB	=	libutils.a

FLAGS	=	-I$(ROOT)/include

all:	compile	lib

compile:
	gcc -c $(SRC) $(FLAGS)

lib:
	ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LINKLIB)$(NAMELIB)

re:	fclean	all
