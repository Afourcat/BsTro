##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

DOX	:=	$(shell doxygen --version 2> /dev/null)

CTC	:=	$(shell ctc --version 2> /dev/null)

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

get_tests:
	@rm -f tests
	@echo -e "Preparing to \033[32mclone\033[0m the \033[34mtest repo\033[0m ..."
	@echo -e "Use your \033[32musername\033[0m and \033[34mpassword\033[0m from the gogs server"
	@git clone http://projects.nwmqpa.com/nwmqpa/bistro-matics-tests.git tests
	@echo -e "The \033[34mtest repo\033[0m has been \033[32mcloned\033[0m !"
	@echo -e "Don't forget that the tests directory is a \033[31mseparate\033[0m repository. You must \033[32mcommit\033[0m your changes inside the \033[34m repo folder\033[0m"

doc:
ifndef DOX
	@echo -e "No doxygen has been found"
else
	@echo -e "The \033[32mgeneration\033[0m of the \033[34mdocumentation\033[0m has \033[32mstarted\033[0m"
	@doxygen -s bonus/doc_config 1>/dev/null
	@echo -e "The \033[34mdocumentation\033[0m has been \033[32msuccessfully generated\033[0m"
endif
