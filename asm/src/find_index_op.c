/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** find_index_op
*/

#include "corewar.h"

int find_index_op(char *mnemonique)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(mnemonique, op_tab[i].mnemonique))
            return i;
    }
    return -1;
}