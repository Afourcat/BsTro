##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile that call the Makefile of each operator
##

all:
	@echo -e "┣━━━━━━The \033[32mcompilation\033[0m of the \033[34moperators\033[0m has \033[32mstarted\033[0m"
	@make -C add/
	@make -C sub/
	@make -C mul/
	@make -C div/
	@make -C mod/
	@make -C pow/
	@echo -e "┣━━━━━━The \033[32mcompilation\033[0m of the \033[34moperators\033[0m has \033[32mfinished\033[0m"

clean:
	@make -C add/ clean
	@make -C sub/ clean
	@make -C mul/ clean
	@make -C div/ clean
	@make -C mod/ clean
	@make -C pow/ clean

fclean:
	@make -C add/ fclean
	@make -C sub/ fclean
	@make -C mul/ fclean
	@make -C div/ fclean
	@make -C mod/ fclean
	@make -C pow/ fclean

re:
	@make -C add/ re
	@make -C sub/ re
	@make -C mul/ re
	@make -C div/ re
	@make -C mod/ re
	@make -C pow/ re

debug:
	@echo -e "┣━━━━━━The \033[32mcompilation\033[0m of the \033[34moperators\033[0m \033[31min debug mode\033[0m has \033[32mstarted\033[0m"
	@make -C add/ debug
	@make -C sub/ debug
	@make -C mul/ debug
	@make -C div/ debug
	@make -C mod/ debug
	@make -C pow/ debug
	@echo -e "┣━━━━━━The \033[32mcompilation\033[0m of the \033[34moperators\033[0m \033[31min debug mode\033[0m has \033[32mfinished\033[0m"
