##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

ROOT		=	$(realpath ..)

LIB		=	-ladd -lparser -lutils

OBJ		=	$(SRC_UT:.c=.o)

CFLAGS		=	-I$(ROOT)/include -Wall -Wextra --coverage -g

LDFLAGS		=	-L$(ROOT)/lib -L/usr/local/lib -lcriterion -lgcov

NAME		=	units


all:		
		gcc -o $(NAME) tests_pf_tree.c tests_stack.c tests_stack_void.c tests_postfix.c $(CFLAGS) $(LDFLAGS) $(LIB)

buildlib:
		make -C ../ buildlib

add:
		gcc -o $(NAME) tests_add.c $(CFLAGS) $(LDFLAGS) -ladd -lutils

sub:
		gcc -o $(NAME) tests_sub.c $(CFLAGS) $(LDFLAGS) -lsub -ladd -lutils

parser:
		gcc -o $(NAME) tests_parser.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

postfix:
		gcc -o $(NAME) tests_postfix.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

stack:
		gcc -o $(NAME) tests_stack.c $(CFLAGS) $(LDFLAGS) -lutils

stack_void:
		gcc -o $(NAME) tests_stack_void.c $(CFLAGS) $(LDFLAGS) -lutils

pf_tree:
		gcc -o $(NAME) tests_pf_tree.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -f *.gcno
		rm -f *.gcda

re:		fclean all
