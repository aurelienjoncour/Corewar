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
    if (parameters[1] > 0 && parameters[1] <= nb)
        live_msg(corewar->array[parameters[1] - 1]);
    free(parameters);
    return EXIT_SUCCESS;
}