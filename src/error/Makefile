##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile utils functions
##

ROOT		=	$(realpath ../..)

SRC		=	error_display.c

OBJ		=	$(SRC:.c=.o)

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	liberror.a

FLAGS		=	-I$(ROOT)/include


all:		compile	lib
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m"

compile:
		@gcc -c $(SRC) $(FLAGS)

lib:
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(LINKLIB)$(NAMELIB)

re:		fclean	all

debug:		fclean
		@gcc -c $(SRC) $(FLAGS) -g
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m \033[31min debug mode\033[0m"
