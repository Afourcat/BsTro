##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro
##

all:
	make -C src/

lib:
	make -C src/ lib

clean:
	make -C src/ clean

fclean:
	make -C src/ fclean

re:
	make -C src/ re

debug:	fclean
	make -C src/ debug
