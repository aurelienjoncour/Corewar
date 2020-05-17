/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** live
*/

#include "corewar.h"

static int get_idx(int param, corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);

    for (int i = 0; i < nb; i++) {
        if (corewar->array[i]->prog_number == param)
            return i;
    }
    return 0;
}

int live(corewar_t *corewar, champions_t *champion)
{
    unsigned int nb = nb_champions(corewar->array);
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (parameters == NULL)
        return EXIT_ERROR;
    if (check_parameters(parameters, 1) == false)
        return EXIT_FAILURE;
    if (parameters[1] > 0 && parameters[1] <= nb) {
        live_msg(corewar->array[get_idx(parameters[1], corewar)]);
        corewar->last_alive = parameters[1];
        corewar->array[get_idx(parameters[1], corewar)]->program->live = 1;
    }
    corewar->nbr_live++;
    if (corewar->nbr_live >= NBR_LIVE) {
        corewar->nbr_cycle_to_die -= CYCLE_DELTA;
        corewar->nbr_live = 0;
    }
    free(parameters);
    return EXIT_SUCCESS;
}