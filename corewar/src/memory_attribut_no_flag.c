/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

void attribut_memory_no_flag(champions_t *champ)
{
    size_t unit = MEM_SIZE / MAX_NB_CHAMPIONS;

    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++)
        champ[i].load_address = unit * i;
}