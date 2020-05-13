/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Long Load Operation
*/

#include "corewar.h"

void lld(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (check_parameters(parameters, 13) == false)
        return;
    if (parameters[0] == T_DIR)
        champion->program->reg[parameters[3]] = parameters[1];
    if (parameters[0] == T_IND)
        champion->program->reg[parameters[3]] =
        corewar->memory[champion->program->pc + parameters[1]
        % MEM_SIZE];
    if (champion->program->reg[parameters[3]] == 0)
        champion->program->carry = 1;
    else
        champion->program->carry = 0;
    free(parameters);
}