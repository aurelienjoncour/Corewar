/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

static bool is_dup(champions_t *champ, int val)
{
    for (int i = 0; i < MAX_NB_CHAMPIONS; i++)
        if (champ[i].prog_number == val)
            return true;
    return false;
}

static int get_value(champions_t *champ)
{
    for (int i = 0; i < MAX_NB_CHAMPIONS; i++)
        if (!is_dup(champ, i))
            return i;
    return -1;
}

void attribut_number(champions_t *champ)
{
    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++)
        if (champ[i].prog_number == -1)
            champ[i].prog_number = get_value(champ);
}

void attribut_memory(champions_t *champ)
{
    size_t unit = MEM_SIZE / MAX_NB_CHAMPIONS;

    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++)
        champ[i].load_address = unit * i;
}