/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** free_word_array
*/

#include <stdlib.h>

void free_word_array(char **array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}