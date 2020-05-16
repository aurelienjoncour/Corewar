/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Add Operation
*/

#include "corewar.h"

int add(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (parameters == NULL)
        return EXIT_ERROR;
    if (!check_parameters(parameters, 4))
        return EXIT_FAILURE;
    champion->program->reg[parameters[5] - 1] =
    champion->program->reg[parameters[1] - 1] +
    champion->program->reg[parameters[3] - 1];
    if (champion->program->reg[parameters[5] - 1] == 0)
        champion->program->carry = 1;
    else
        champion->program->carry = 0;
    free(parameters);
    return EXIT_SUCCESS;
}