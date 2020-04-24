/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** dup_word_array
*/

#include <stdlib.h>
#include "my.h"

char **dup_word_array(char **array)
{
    char **dup;
    size_t size = len_word_array(array);

    dup = malloc(sizeof(char *) * (size + 1));
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; array[i] != NULL; i++) {
        dup[i] = my_strdup(array[i]);
        if (dup[i] == NULL)
            return NULL;
    }
    dup[size] = NULL;
    return dup;
}