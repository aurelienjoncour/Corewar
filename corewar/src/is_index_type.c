/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_index_type
*/

#include "corewar.h"

bool is_index_type(char code)
{
    for (size_t i = 0; index_list[i]; i++) {
        if (index_list[i] == code)
            return true;
    }
    return false;
}