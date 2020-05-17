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
				$(SRC_DIR)operation/live.c				\
				$(SRC_DIR)operation/add.c				\
				$(SRC_DIR)operation/aff.c				\
				$(SRC_DIR)operation/and.c				\
				$(SRC_DIR)operation/fork.c				\
				$(SRC_DIR)operation/ld.c				\
				$(SRC_DIR)operation/ldi.c				\
				$(SRC_DIR)operation/lfork.c				\
				$(SRC_DIR)operation/lld.c				\
				$(SRC_DIR)operation/lldi.c				\
				$(SRC_DIR)operation/or.c				\
				$(SRC_DIR)operation/st.c				\
				$(SRC_DIR)operation/sti.c				\
				$(SRC_DIR)operation/sub.c				\
				$(SRC_DIR)operation/xor.c				\
				$(SRC_DIR)operation/zjmp.c				\
				$(SRC_DIR)sort_champions.c				\
				$(SRC_DIR)loop.c						\
				$(SRC_DIR)check_parameters.c			\
				$(SRC_DIR)get_parameters.c				\
				$(SRC_DIR)write_int_in_mem.c			\
				$(SRC_DIR)update_pc.c					\
				$(SRC_DIR)is_index_type.c				\
				$(SRC_DIR)get_int_in_memory.c			\
				$(SRC_DIR)dead_management.c				\

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
