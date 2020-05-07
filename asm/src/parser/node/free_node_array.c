/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_node_array
*/

#include "corewar.h"

void free_node_array(token_t **array)
{
    for (size_t i = 0; array[i] != NULL; i++)
        destroy_list(array[i]);
    free(array);
}