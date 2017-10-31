##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile parser's functions
##

SRC		=	pf_tree.c	\
			postfix.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-L ../../lib -I../../include

LINKLIB		=	../../lib/

NAMELIB		=	libparser.a

all:		compile lib
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m"

lib:
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

compile:
		@gcc -c $(SRC) $(FLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(LINKLIB)$(NAMELIB)

re:		fclean	all

debug:		fclean
		@gcc -c $(SRC) $(FLAGS) -g
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m \033[31min debug mod\033[0m"
