/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_index_type
*/

#include "corewar.h"

bool is_index_type(char *mnemonique)
{
    for (size_t i = 0; index_list[i] != NULL; i++) {
        if (!my_strcmp(index_list[i], mnemonique))
            return true;
    }
    return false;
}