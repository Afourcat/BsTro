##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

all:
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mbistro-matic\033[0m has \033[32mstarted\033[0m"
	@make --no-print-directory -C src/
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mbistro-matic\033[0m has \033[32mfinished\033[0m"

buildlib:
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mlibs\033[0m has \033[32mstarted\033[0m"
	@make --no-print-directory -C src/ buildlib
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mlibs\033[0m has \033[32mfinished\033[0m"

clean:
	@echo -e "The \033[32mcleaning\033[0m of the \033[34mobjects files\033[0m has \033[32mstarted\033[0m"
	@rm -f -R bonus/doc
	@make --no-print-directory -C src/ clean
	@make --no-print-directory -C tests/ clean
	@echo -e "The \033[32mcleaning\033[0m of the \033[34mobjects files\033[0m has \033[32mfinished\033[0m"

fclean: clean
	@echo -e "The \033[32mcleaning\033[0m of the \033[34mbinary files\033[0m has \033[32mstarted\033[0m"
	@make --no-print-directory -C src/ fclean
	@make --no-print-directory -C tests/ fclean
	@make --no-print-directory -C tests/bash_tests fclean
	@echo -e "The \033[32mcleaning\033[0m of the \033[34mbinary files\033[0m has \033[32mfinished\033[0m"

re:	fclean all

debug:
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mbistro-matic\033[0m \033[31min debug mode\033[0m has \033[32mstarted\033[0m"
	@make --no-print-directory -C src/ debug
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mbistro-matic\033[0m \033[31min debug mode\033[0m has \033[32mfinished\033[0m"

push:	fclean
	git push origin master

doc:
	@echo -e "The \033[32mgeneration\033[0m of the \033[34mdocumentation\033[0m has \033[32mstarted\033[0m"
	@doxygen -s bonus/doc_config | grep -v "\.\.\." | grep -v "Searching"
	@echo -e "The \033[34mdocumentation\033[0m has been \033[32msuccessfully generated\033[0m"
