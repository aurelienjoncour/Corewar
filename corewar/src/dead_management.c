/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** dead_management
*/

#include "corewar.h"

int nb_death(corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);
    int dead = 0;

    for (int i = 0; i < nb; i++) {
        if (corewar->array[i]->program->live == -1)
            dead++;
    }
    return dead;
}

int check_dead(corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);
    int dead = 0;

    for (int i = 0; i < nb; i++) {
        if (!corewar->array[i]->program->live) {
            corewar->array[i]->program->live = -1;
        }
        if (corewar->array[i]->program->live != -1) {
            corewar->array[i]->program->live = 0;
        }
    }
    dead = nb_death(corewar);
    if (dead == nb - 1 || dead == nb)
        return true;
    return false;
}