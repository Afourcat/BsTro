##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile which compile everything
##

ROOT		=	$(realpath ..)

NAME		=	calc

FLAGS		=	-L../lib

LIBS		=	-lutils -lparser -ladd -lsub -lmul -lpow -lerror

all:		buildlib
		gcc -o $(ROOT)/$(NAME) $(FLAGS) $(LIBS)

buildlib:
		make -C operator/
		make -C utils/
		make -C error/
		make -C parser/

clean:
		make -C operator/ clean
		make -C utils/ clean
		make -C error/ clean
		make -C parser/ clean

fclean:
		make -C operator/ fclean
		make -C utils/ fclean
		make -C error/ fclean
		make -C parser/ fclean

re:
		make -C operator/ re
		make -C utils/ re
		make -C error/ re
		make -C parser/ re

debug:
		make -C operator/ debug
		make -C utils/ debug
		make -C parser/ debug
		make -C error/ debug
#		gcc -o $(NAME) $(FLAGS) $(LIBS) -g
