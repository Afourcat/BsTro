##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the sub system
##

ROOT		=	$(realpath ../../..)

SRC		=	infin_sub.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I$(ROOT)/include

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	libsub.a

all:		compile	lib

compile:
		@gcc -c $(SRC) $(FLAGS)
		@echo -e "┃      ┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m"

lib:
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(LINKLIB)$(NAMELIB)

re:		clean all

debug:		fclean
		@gcc -c $(SRC) $(FLAGS) -g
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
		@echo -e "┃      ┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m \033[31min debug mode\033[0m"
