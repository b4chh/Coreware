##
## EPITECH PROJECT, 2019
## Lib my
## File description:
## Makefile
##

CC	=	gcc

CPPFLAGS	=	-I../include
CFLAGS		=	--coverage

SRC		:=

LFLAGS	=	-L../lib/my -lmy	\
			-L../lib/list -llist -lcriterion

OBJ_PATH	:= ../obj
OBJ		=	$(SRC:.c=.o)

NAME	=	unit_tests

get_obj	=	$(OBJ_PATH)/$(notdir $(1))

all: $(NAME)

%.o:	%.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(LFLAGS) &&  \
	echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" && \
	mv $@ $(OBJ_PATH)/$(notdir $@)  || \
	echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) \
	$(foreach obj, $(OBJ), $(call get_obj,$(obj))) $(LFLAGS)
	mv $(NAME) ../

clean:
	rm -f $(foreach wrd, $(OBJ), $(call get_obj,$(wrd)))