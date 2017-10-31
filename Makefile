##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

all:
	@make -C src/

buildlib:
	@make -C src/ buildlib

clean:
	rm -f -R bonus/doc
	@make -C src/ clean
	@make -C tests/ clean

fclean: clean
	@make -C src/ fclean
	@make -C tests/ fclean
re:
	@make -C src/ re

debug:
	@make -C src/ debug

push:	fclean
	git push origin master

doc:
	doxygen bonus/doc_config
