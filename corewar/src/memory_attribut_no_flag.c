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

bool error_manage_dup(champions_t *champ)
{
    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++) {
        if (champ[i].load_address == -1)
            return false;
        for (size_t u = 0; u < MAX_NB_CHAMPIONS; u++) {
            if (i != u && champ[i].load_address == champ[u].load_address)
                return false;
        }
    }
    return true;
}