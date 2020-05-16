/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Store Operation
*/

#include "corewar.h"

int st(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (parameters == NULL)
        return EXIT_ERROR;
    if (!check_parameters(parameters, 3))
        return EXIT_FAILURE;
    if (parameters[2] == T_REG)
        champion->program->reg[parameters[3] - 1] =
        champion->program->reg[parameters[1] - 1];
    if (parameters[2] == T_IND)
        write_int_in_mem(corewar->memory,
        (champion->program->pc + parameters[3] % IDX_MOD) % MEM_SIZE,
        champion->program->reg[parameters[1] - 1]);
    free(parameters);
    return EXIT_SUCCESS;
}