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
				$(SRC_DIR)usage.c						\
				$(SRC_DIR)clean_line.c					\
				$(SRC_DIR)get_line.c					\
				$(SRC_DIR)compile_champions.c			\
				$(SRC_DIR)create_file.c					\
				$(SRC_DIR)error_syntax_line.c			\
				$(SRC_DIR)error_params.c				\
				$(SRC_DIR)find_index_op.c				\
				$(SRC_DIR)get_instruction.c				\
				$(SRC_DIR)get_prog_size.c				\
				$(SRC_DIR)tools/allowed_char.c			\
				$(SRC_DIR)header/get_header.c			\
				$(SRC_DIR)header/write_header.c			\
				$(SRC_DIR)header/get_name.c				\
				$(SRC_DIR)header/get_comment.c			\
				$(SRC_DIR)compile/read_file.c			\
				$(SRC_DIR)compile/comment_manage.c		\
				$(SRC_DIR)compile/line_manage.c			\
				$(SRC_DIR)parser/node/add_node.c		\
				$(SRC_DIR)parser/node/connect_node.c	\
				$(SRC_DIR)parser/node/create_node.c		\
				$(SRC_DIR)parser/node/rm_node.c			\
				$(SRC_DIR)parser/node/destroy_list.c	\
				$(SRC_DIR)parser/node/display_list.c	\
				$(SRC_DIR)parser/node/rm_next_node.c	\
				$(SRC_DIR)parser/node/add_node_at_the_end.c	\
				$(SRC_DIR)parser/node/realloc_node_array.c	\
				$(SRC_DIR)parser/node/free_node_array.c	\
				$(SRC_DIR)parser/parser_tab.c			\
				$(SRC_DIR)parser/tokeniser.c			\
				$(SRC_DIR)parser/rm_useless_separator.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	asm

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