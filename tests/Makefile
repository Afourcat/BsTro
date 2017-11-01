##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile used for unit tests
##

ROOT		=	$(realpath ..)

LIB		=	-lconvert_base -lmod -ldiv -lpow -lsub -lmul -ladd -lparser -lerror -lutils

CFLAGS		=	-I$(ROOT)/include -Wall -Wextra --coverage -g

LDFLAGS		=	-L$(ROOT)/lib -L/usr/local/lib -lcriterion -lgcov

NAME		=	units


all:		
		@gcc -o $(NAME) tests_pf_tree.c tests_stack.c tests_stack_void.c tests_postfix.c				\
		tests_mul.c tests_div.c tests_sub.c tests_add.c tests_pow.c tests_mod.c tests_convert_base.c $(CFLAGS) $(LDFLAGS) $(LIB)

buildlib:
		make -C ../ buildlib

add:
		@gcc -o $(NAME) tests_add.c $(CFLAGS) $(LDFLAGS) -ladd -lutils

sub:
		@gcc -o $(NAME) tests_sub.c $(CFLAGS) $(LDFLAGS) -lsub -ladd -lutils

mul:
		@gcc -o $(NAME) tests_mul.c $(CFLAGS) $(LDFLAGS) -lmul -ladd -lutils

div:
		@gcc -o $(NAME) tests_div.c $(CFLAGS) $(LDFLAGS) -ldiv -lpow -lmul -lsub -ladd -lutils -lerror

pow:
		@gcc -o $(NAME) tests_pow.c $(CFLAGS) $(LDFLAGS) -lpow -lmul -ladd -lsub -lutils

mod:
		@gcc -o $(NAME) tests_mod.c $(CFLAGS) $(LDFLAGS) -lmod -ldiv -lmul -ladd -lsub -lutils

parser:
		@gcc -o $(NAME) tests_parser.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

postfix:
		@gcc -o $(NAME) tests_postfix.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

stack:
		@gcc -o $(NAME) tests_stack.c $(CFLAGS) $(LDFLAGS) -lutils

stack_void:
		@gcc -o $(NAME) tests_stack_void.c $(CFLAGS) $(LDFLAGS) -lutils

pf_tree:
		@gcc -o $(NAME) tests_pf_tree.c $(CFLAGS) $(LDFLAGS) -lparser -lutils

clean:
		@rm -f *.gcno
		@rm -f *.gcda

fclean: 	clean
		@rm -f $(NAME)

re:		fclean all
