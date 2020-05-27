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

SRC	:=	src/main.c \
		src/compile.c \
		src/reverse.c \
		src/files/file_operations.c \
		src/info/create_info.c \
		src/info/destroy_info.c \
		src/tokenizer/create_tokenizer.c \
		src/tokenizer/destroy_tokenizer.c \
		src/tokenizer/run_lexer.c \
		src/tokenizer/eat.c \
		src/tokenizer/parse_label_dec_token.c \
		src/tokenizer/skip_white_spaces.c \
		src/tokenizer/get_header_info.c \
		src/tokenizer/parse_instruction_token.c \
		src/tokenizer/parse_register_token.c \
		src/tokenizer/parse_mnemonic_token.c \
		src/tokenizer/parse_direct_token.c \
		src/tokenizer/parse_indirect_token.c \
		src/data_buffer/buffer_operations.c \
		src/data_buffer/comments.c \
		src/parser/create_parser.c \
		src/parser/destroy_parser.c \
		src/parser/get_operation.c \
		src/parser/run_parser.c \
		src/parser/encode_header.c \
		src/parser/parse_args.c \
		src/directive/create_directive.c \
		src/directive/destroy_directive.c \
		src/directive/arguments/create_arg.c \
		src/directive/arguments/destroy_arg.c \
		src/directive/arguments/bytes_label_behind.c \
		src/directive/arguments/bytes_label_after.c \
		src/directive/arguments/indexes_arg.c \
		src/directive/arguments/success_label_checker.c \
		src/directive/arguments/get_params_byte.c \
		src/compilation/encoding.c \
		src/tokenizer/trim_start_spaces.c

OBJ	=	$(SRC:.c=.o)
OBJ_PATH	:=	./obj

NAME	=	asm

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

.PHONY	=	all asm libs init clean fclean re
