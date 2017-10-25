##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile which compile everything
##

NAME	=	calc

FLAGS	=	-L../lib

LIBS	=	-lutils -lparser -ladd -lsub -lmul

all:
	make -C operator/
	make -C utils/
	make -C parser/
	gcc -o $(NAME) $(FLAGS) $(LIBS)

lib:
	make -C operator/
	make -C utils/
	make -C parser/

clean:
	make -C operator/ clean
	make -C utils/ clean
	make -C parser/ clean

fclean:
	make -C operator/ fclean
	make -C utils/ fclean
	make -C parser/ fclean

re:
	make -C operator/ re
	make -C utils/ re
	make -C parser/ re

