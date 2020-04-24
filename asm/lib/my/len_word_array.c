/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** len_word_array
*/

#include <stdlib.h>

size_t len_word_array(char **array)
{
    size_t i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}