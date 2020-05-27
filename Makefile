##
## EPITECH PROJECT, 2019
## Lib my
## File description:
## Makefile
##

CC	=	gcc

DEBUG_FLAGS = -g3 -ggdb

CFLAGS	=	-W -Wall -Wextra -g
ifeq ($(DEBUG), yes)
	CFLAGS	:= $(CFLAGS) $(DEBUG_FLAGS)
endif
SHELL:=/bin/bash
CPPFLAGS	:=	-I./include
LFLAGS	+=	-L./lib/my -lmy	\
		-L./lib/list -llist

LIBS	=	libs

NAME	=	full

all: $(NAME)

$(NAME):
	make -C asm
	make -C corewar

tests_run:
	make -C asm tests_run
	make -C corewar tests_run
	./asm/unit_tests
	./vm/unit_tests

clean:
	make -C asm clean
	make -C corewar clean

clean_tests:
	make -C asm clean_tests
	make -C corewar clean_tests

fclean: clean clean_tests
	@make -C lib/my fclean
	@make -C lib/list fclean
	@make -C asm fclean
	@make -C corewar fclean

re: clean all

.PHONY	=	all full clean clean_tests fclean re tests_run
