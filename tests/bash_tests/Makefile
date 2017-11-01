##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

ROOT		=	$(realpath ../..)

LIB		=	-lconvert_base -lmod -ldiv -lpow -lsub -lmul -ladd -lparser -lerror -lutils

CFLAGS		=	-I$(ROOT)/include -w --coverage -g

LDFLAGS		=	-L$(ROOT)/lib -L/usr/local/lib -lcriterion -lgcov

NAME		=	units


all:		addO subO mulO 

buildlib:
		make -C ../../ buildlib

addO:
		gcc -o add/infin_add add/main.c $(CFLAGS) $(LDFLAGS) -ladd -lutils

subO:
		gcc -o sub/infin_sub sub/main.c $(CFLAGS) $(LDFLAGS) -lsub -ladd -lutils

mulO:
		gcc -o mul/infin_mul mul/main.c $(CFLAGS) $(LDFLAGS) -lmul -ladd -lutils

clean:
		rm -f *.gcno
		rm -f *.gcda

fclean: 	clean
		rm -f add/infin_add
		rm -f add/infin_sub
		rm -f add/infin_mul
		rm -f comp1
		rm -f comp2

re:		fclean all
