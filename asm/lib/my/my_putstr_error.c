/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_putstr_error
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr_error(char const *str)
{
    write(STDERR_FILENO, str, my_strlen(str));
    return 0;
}
