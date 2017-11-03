##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile which compile everything
##

ROOT		=	$(realpath ..)

NAME		=	calc

FLAGS		=	-L../lib -I../include

LIBS		=	-lparser -lcalc -lmod -ldiv -lconvert_base -lpow -lmul -lsub -ladd -lerror -lutils

all:		buildlib
		@gcc -o $(ROOT)/$(NAME) main.c $(FLAGS) $(LIBS) 

buildlib:
		@make -C operator/
		@make -C utils/
		@make -C error/
		@make -C parser/
		@make -C convert_base/
		@make -C calc_engine/

clean:
		@make -C operator/ clean
		@make -C utils/ clean
		@make -C error/ clean
		@make -C parser/ clean
		@make -C convert_base/ clean
		@make -C calc_engine/ clean

fclean:
		@make -C operator/ fclean
		@make -C utils/ fclean
		@make -C error/ fclean
		@make -C parser/ fclean
		@make -C convert_base/ fclean
		@make -C calc_engine/ fclean
		@rm -rf $(ROOT)/$(NAME)

re:
		@make -C operator/ re
		@make -C utils/ re
		@make -C error/ re
		@make -C parser/ re
		@make -C convert_base/ re
		@make -C calc_engine/ re

debug:
		@make -C operator/ debug
		@make -C utils/ debug
		@make -C parser/ debug
		@make -C error/ debug
		@make -C convert_base/ debug
		@make -C calc_engine/ debug
		@gcc -o $(ROOT)/$(NAME) main.c $(FLAGS) $(LIBS) -g
