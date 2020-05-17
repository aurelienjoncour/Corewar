/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** live
*/

#include "corewar.h"

int live(corewar_t *corewar, champions_t *champion)
{
    int nb = nb_champions(corewar->array);
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (parameters == NULL)
        return EXIT_ERROR;
    if (check_parameters(parameters, 1) == false)
        return EXIT_FAILURE;
    if (parameters[1] > 0 && parameters[1] <= nb) {
        live_msg(corewar->array[parameters[1] - 1]);
        corewar->last_alive = parameters[1];
        champion->program->live = 1;
    }
    corewar->nbr_live++;
    if (corewar->nbr_live >= NBR_LIVE) {
        corewar->nbr_cycle_to_die -= CYCLE_DELTA;
        corewar->nbr_live = 0;
    }
    free(parameters);
    return EXIT_SUCCESS;
}