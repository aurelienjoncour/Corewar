/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** realloc_node_array
*/

#include "corewar.h"

token_t **realloc_node_array(token_t **array_src, size_t size)
{
    token_t **array = malloc(sizeof(token_t *) * size);
    size_t i = 0;

    if (array == NULL)
        return NULL;
    for (i = 0; array_src[i] != NULL; i++)
        array[i] = array_src[i];
    for (; i < size; i++)
        array[i] = NULL;
    free(array_src);
    return array;
}
