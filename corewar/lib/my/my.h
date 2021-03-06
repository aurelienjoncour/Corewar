/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** prototypes of libmy function
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <stdbool.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char const *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int nb);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(const char *src);
char *my_strndup(const char *str, int n);
char **my_str_to_word_array(char *str, char *delim);
int my_strchr(const char *str, char c);
int my_str_isalphanum(char const *str);
bool my_char_isalpha(char c);
void free_word_array(char **array);
size_t len_word_array(char **array);
char **dup_word_array(char **array);
char **realloc_word_array(char **array);
bool my_char_is_allowed(const char *script, const char *allow_char);
int my_putstr_error(char const *str);
char *my_putnbr_base_in_str(long long int nbr, char const *base);
char *my_put_nbr_in_str(long long int nb);
int my_putnbr_base(long long int nbr, char const *base);

#endif
