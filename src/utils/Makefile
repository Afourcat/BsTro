##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that compile utils functions
##

ROOT		=	$(realpath ../..)

SRC		=	display.c	 \
			my_atoi.c	 \
			stack.c		 \
			stack_void.c	 \
			memory.c 	 \
			str_utils.c	 \
			str_nb_utils.c   \
			str_nb_utils_2.c \
			str_nb_utils_3.c \
			my_strdup.c	

OBJ		=	$(SRC:.c=.o)

LINKLIB		=	$(ROOT)/lib/

NAMELIB		=	libutils.a

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
		@echo -e "┣━━━━━━The \033[34m$(NAMELIB)\033[0m has been \033[32mcompiled\033[0m and \033[32mlinked\033[0m \033[31min debug mod\033[0m"
