##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile parser's functions
##

SRC		=	convert_base.c

OBJ		=	$(SRC:.c=.o)

FLAGS		=	-L ../../lib -I../../include

LINKLIB		=	../../lib/

NAMELIB		=	libconvert_base.a

all:		compile lib
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m"

lib:
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)

compile:
		@gcc -c $(SRC) $(FLAGS)

clean:
		@rm -f *.gcno
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(LINKLIB)$(NAMELIB)

re:		fclean	all

debug:		fclean
		@gcc -c $(SRC) $(FLAGS) -g
		@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m \033[31min debug mode\033[0m"

coverage:
	@gcc -c $(SRC) $(FLAGS) -ftest-coverage -g
	@ar rc $(LINKLIB)$(NAMELIB) $(OBJ)
