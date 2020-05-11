##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c				\
				$(SRC_DIR)op.c					\
				$(SRC_DIR)constant.c			\
				$(SRC_DIR)tools/usage.c			\
				$(SRC_DIR)tools/allowed_char.c	\
				$(SRC_DIR)get_argument.c		\
				$(SRC_DIR)operation/and.c		\
				$(SRC_DIR)flag.c				\

OBJ			=	$(SRC:.c=.o)

NAME		=	corewar

CFLAGS		+=	-Wall -Wextra -I./include

LDLFLAGS	+= -L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS)

clean:
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(OBJ)

fclean:		clean
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

tests_run:		fclean all
				make -C tests/

debugs:	CFLAGS += -g
debugs: re

.PHONY: all clean fclean re run tests_run debugs