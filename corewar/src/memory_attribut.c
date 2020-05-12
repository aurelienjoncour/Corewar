/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

static bool collision(champions_t *cp, int start, int end, size_t i)
{
    int unit = MEM_SIZE / MAX_NB_CHAMPIONS;

    if (start < end) {
        if (cp[i].load_address > start && cp[i].load_address < end)
            return true;
        if (cp[i].load_address + unit > start &&
            cp[i].load_address + unit < end)
            return true;
    }
    else {
        if (cp[i].load_address > start || cp[i].load_address < end)
            return true;
        if ((cp[i].load_address + unit) % MEM_SIZE > start ||
            (cp[i].load_address + unit) % MEM_SIZE < end)
            return true;
    }
    return false;
}

static bool comflict_memory(champions_t *champ, int start, int end)
{
    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++) {
        if (champ[i].load_address != -1) {
            if (collision(champ, start, end, i))
                return false;
        }
    }
    return true;
}

static bool end_memory(champions_t *champ, ssize_t pos)
{
    size_t pres = champ[pos].load_address + (MEM_SIZE / MAX_NB_CHAMPIONS);

    for (size_t i = 0; i < (size_t) pos; i++)
        if (champ[i].load_address == -1) {
            if (!comflict_memory(champ,
                pres, pres + (MEM_SIZE / MAX_NB_CHAMPIONS)))
                return false;
            else {
                champ[i].load_address = pres;
                pres = (pres + (MEM_SIZE / MAX_NB_CHAMPIONS)) % MEM_SIZE;
            }
        }
        else {
            pres = (champ[i].load_address + (MEM_SIZE / MAX_NB_CHAMPIONS)) % MEM_SIZE;
        }
    return true;
}

static bool active_memory(champions_t *champ, ssize_t pos)
{
    size_t pres = champ[pos].load_address + (MEM_SIZE / MAX_NB_CHAMPIONS);

    for (size_t i = pos; i < MAX_NB_CHAMPIONS; i++)
        if (champ[i].load_address == -1) {
            if (!comflict_memory(champ,
                pres, pres + (MEM_SIZE / MAX_NB_CHAMPIONS)))
                return false;
            else {
                champ[i].load_address = pres;
                pres = (pres + (MEM_SIZE / MAX_NB_CHAMPIONS)) % MEM_SIZE;
            }
        }
        else {
            pres = (champ[i].load_address + (MEM_SIZE / MAX_NB_CHAMPIONS)) % MEM_SIZE;
        }
    return end_memory(champ, pos);
}

bool attribut_memory(champions_t *champ)
{
    ssize_t pos = -1;

    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++)
        if (champ[i].load_address != -1) {
            pos = i;
            break;
        }
    if (pos == -1) {
        attribut_memory_no_flag(champ);
        return true;
    }
    else {
        return active_memory(champ, pos);
    }
}