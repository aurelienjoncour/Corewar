##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles libmy
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c			\
		my_isneg.c					\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strupcase.c				\
		my_swap.c					\
		my_getnbr.c					\
		my_strstr.c					\
		my_strdup.c					\
		my_str_to_word_array.c		\
		my_strndup.c				\
		my_strchr.c					\
		my_str_isalphanum.c			\
		my_char_is_alpha.c			\
		len_word_array.c			\
		free_word_array.c			\
		dup_word_array.c			\
		realloc_word_array.c		\
		my_char_is_allowed.c		\
		my_putstr_error.c			\

OBJ	=	$(SRC:.c=.o)

NAME =	libmy.a

all: $(NAME)

CFLAGS = -g -Wall -Wextra -Werror -Wpedantic

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include
	cp $(NAME) ../
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

auteur:
	echo $(USER) > auteur
