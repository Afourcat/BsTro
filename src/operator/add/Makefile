##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile the add system
##

ROOT		=	$(realpath ../../..)

SRC		=	infin_add.c	\
			add_utils.c	\
			test_add.c	

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-I$(ROOT)/include

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	libadd.a

all:		compile lib

lib:
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
		@echo -e "┃      ┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m"

compile:
		@gcc -c $(SRC) $(FLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(LINKLIB)$(NAMELIB)

re:		clean all

debug:		fclean
		@gcc -c $(SRC) $(FLAGS) -g
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
		@echo -e "┃      ┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m \033[31min debug mode\033[0m"


