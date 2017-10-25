##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

all:
	make -C src/

buildlib:
	make -C src/ buildlib

clean:
	make -C src/ clean

fclean:
	make -C src/ fclean

re:
	make -C src/ re

debug:	fclean
	make -C src/ debug
