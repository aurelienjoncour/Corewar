##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c						\
				$(SRC_DIR)op.c							\
				$(SRC_DIR)constant.c					\
				$(SRC_DIR)read_ins.c					\
				$(SRC_DIR)create_memory.c				\
				$(SRC_DIR)create_program.c				\
				$(SRC_DIR)write_on_memory.c				\
				$(SRC_DIR)champion_attribut.c			\
				$(SRC_DIR)destroy_corewar.c				\
				$(SRC_DIR)init_corewar.c				\
				$(SRC_DIR)init_champions.c				\
				$(SRC_DIR)memory_attribut.c				\
				$(SRC_DIR)realloc_champion_array.c		\
				$(SRC_DIR)nb_champion.c					\
				$(SRC_DIR)tools/usage.c					\
				$(SRC_DIR)tools/allowed_char.c			\
				$(SRC_DIR)get_arg/flag.c				\
				$(SRC_DIR)get_arg/get_argument.c		\
				$(SRC_DIR)display/display_memory.c		\
				$(SRC_DIR)display/display_msg.c			\
				$(SRC_DIR)display/display_pointeur.c	\

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