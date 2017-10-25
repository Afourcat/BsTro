##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

ROOT		=	$(realpath ..)

LIB		=	-lutils -ladd -lsub -lmul -lparser

OBJ		=	$(SRC_UT:.c=.o)

CFLAGS		=	-I$(ROOT)/include -Wall -Wextra --coverage

LDFLAGS		=	-L$(ROOT)/lib -L/usr/local/lib -lcriterion -lgcov

NAME		=	units


all:		buildlib


buildlib:
		make -C ../ lib

add:
		gcc -o $(NAME) tests_add.c $(CFLAGS) $(LDFLAGS) -lutils -ladd

sub:
		gcc -o $(NAME) tests_sub.c $(CFLAGS) $(LDFLAGS) -lutils -lsub -ladd

parser:
		gcc -o $(NAME) tests_parser.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

postfix:
		gcc -o $(NAME) tests_postfix.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

stack:
		gcc -o $(NAME) tests_stack.c $(CFLAGS) $(LDFLAGS) -lutils

stack_void:
		gcc -o $(NAME) tests_stack_void.c $(CFLAGS) $(LDFLAGS) -lutils

pf_tree:
		gcc -o $(NAME) tests_pf_tree.c $(CFLAGS) $(LDFLAGS) -lutils

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
