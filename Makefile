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
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mlibs\033[0m has \033[32mstarted\033[0m"

clean:
	@rm -f -R bonus/doc
	@make --no-print-directory -C src/ clean
	@make --no-print-directory -C tests/ clean

fclean: clean
	@make -Cs src/ fclean
	@make -Cs tests/ fclean
re:
	@make -C src/ re

debug:
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mbistro-matic\033[0m \033[31min debug mode\033[0m has \033[32mstarted\033[0m"
	@make --no-print-directory -C src/ debug
	@echo -e "The \033[32mcompilation\033[0m of the \033[34mbistro-matic\033[0m \033[31min debug mode\033[0m has \033[32mfinished\033[0m"

push:	fclean
	git push origin master

doc:
	@doxygen -s bonus/doc_config
	@echo -e "The \033[34mdocumentation\033[0m has been \033[32msuccessfully generated\033[0m"
