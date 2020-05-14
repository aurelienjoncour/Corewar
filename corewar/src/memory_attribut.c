/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

static bool check_col(int addr, int size, champions_t **champ, size_t i)
{
    if (addr % MEM_SIZE < (addr + size) % MEM_SIZE) {
        if (addr % MEM_SIZE <= champ[i]->load_address &&
            (addr + size) % MEM_SIZE > champ[i]->load_address)
            return true;
    }
    else {
        if (addr % MEM_SIZE <= champ[i]->load_address ||
            (addr + size) % MEM_SIZE > champ[i]->load_address)
            return true;
    }
    return false;
}

static bool overlap(int addr, int size, champions_t **champ, size_t u)
{
    for (size_t i = 0; i < MAX_NB_CHAMPIONS && champ[i]->filepath; i++) {
        if (i != u) {
            if (check_col(addr, size, champ, i))
                return true;
        }
    }
    return false;
}

static bool error_manage_dup(champions_t **champ)
{
    for (size_t i = 0; i < MAX_NB_CHAMPIONS && champ[i]->filepath; i++) {
        if (champ[i]->load_address == -1)
            return false;
        for (size_t u = 0; u < MAX_NB_CHAMPIONS; u++) {
            if (i != u && champ[i]->load_address == champ[u]->load_address)
                return false;
        }
        if (overlap(champ[i]->load_address,
            champ[i]->head->prog_size, champ, i))
            return false;
    }
    return true;
}

static size_t nb_champion(champions_t **champ)
{
    size_t i;

    for (i = 0; i < MAX_NB_CHAMPIONS && champ[i]->filepath; i++);
    return i;
}

bool attribut_memory(champions_t **champ)
{
    int unit = MEM_SIZE / nb_champion(champ);

    for (size_t i = 0; i < MAX_NB_CHAMPIONS && champ[i]->filepath; i++)
        if (champ[i]->load_address == -1)
            champ[i]->load_address = unit * i;
    if (!error_manage_dup(champ))
        return false;
    return true;
}