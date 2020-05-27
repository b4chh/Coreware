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
CPPFLAGS	:=	-I../include
LFLAGS	+=	-L../lib/my -lmy	\
		-L../lib/list -llist

SRC	:=	src/main.c	\
		src/reverse.c \
		src/store_nbr.c \
		src/show_mem.c \
		src/champion/create_champion.c \
		src/champion/destroy_champion.c \
		src/champion/get_header.c \
		src/champion/get_instructions.c	\
		src/champion/duplicate_champion.c \
		src/vm/create_vm.c \
		src/vm/destroy_vm.c \
		src/vm/display_msg.c	\
		src/vm/load_champions.c \
		src/vm/setup_memory.c	\
		src/vm/run_corewar.c \
		src/vm/load_mem.c \
		src/vm/exec_instruction.c \
		src/vm/find_pc.c \
		src/vm/write_memory.c \
		src/vm/load_params.c \
		src/operations/get_operation.c \
		src/operations/indexes_arg.c \
		src/vm/instructions/get_correct_pattern.c \
		src/vm/instructions/arguments/get_args_type_from_byte.c \
		src/vm/instructions/arguments/get_args.c \
		src/vm/params/create_param.c \
		src/vm/params/destroy_param.c \
		src/vm/params/init_addr.c \
		src/vm/params/init_path.c \
		src/vm/params/init_prog_nbr.c

SRC	+=	src/vm/instructions/add.c \
		src/vm/instructions/aff.c \
		src/vm/instructions/and/and.c \
		src/vm/instructions/and/function_of_and.c \
		src/vm/instructions/fork.c \
		src/vm/instructions/ld.c \
		src/vm/instructions/ldi/ldi.c \
		src/vm/instructions/ldi/ldi_2.c \
		src/vm/instructions/lfork.c \
		src/vm/instructions/live.c \
		src/vm/instructions/lld.c \
		src/vm/instructions/lldi/lldi.c \
		src/vm/instructions/lldi/lldi_2.c \
		src/vm/instructions/or/or.c \
		src/vm/instructions/or/function_of_or.c \
		src/vm/instructions/st.c \
		src/vm/instructions/sti/sti.c \
		src/vm/instructions/sti/sti_2.c \
		src/vm/instructions/sub.c \
		src/vm/instructions/xor/xor.c \
		src/vm/instructions/xor/function_of_xor.c \
		src/vm/instructions/zjmp.c

OBJ	=	$(SRC:.c=.o)
OBJ_PATH	:=	./obj

NAME	=	corewar

LIBS	=	libs

all: $(NAME)

get_obj	=	$(OBJ_PATH)/$(notdir $(1))

$(NAME):	$(LIBS) $(OBJ)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) \
	$(foreach obj, $(OBJ), $(call get_obj,$(obj))) $(LFLAGS) && \
	echo -e "\e[1m\e[32m******** Compilation completed ********\033[0m" || \
	echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

%.o:	%.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(LFLAGS) &&  \
	echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" && \
	mv $@ $(OBJ_PATH)/$(notdir $@) || \
	echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

$(LIBS):
	@make -C ../lib/my
	@make -C ../lib/list

init:
	@touch .gitignore && \
	mkdir obj src lib include && \
	echo -e "\e[32m[OK] Project basics initialized" \
	"\033[0m\e[1m\e[32m\033[0m" || echo -e \
	"\e[31m[OK] Project basics already initialized \033[0m\e[1m\e[32m\033[0m"

tests_run: $(LIBS)
	make clean
	make -C tests/
	./unit_tests

clean:
	@rm -f $(foreach wrd, $(OBJ), $(call get_obj,$(wrd)))

clean_tests:
	-rm -f ./unit_tests
	find . -name "*.gcno" -delete -o -name "*.gcda" -delete
	make -C tests/ clean

fclean: clean clean_tests
	@make -C ../lib/my/ fclean
	@make -C ../lib/list fclean
	@rm -f $(NAME)

re: clean all

.PHONY	=	all corewar libs init clean fclean re
