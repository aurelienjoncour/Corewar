/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Store Operation
*/

#include "corewar.h"

void st(corewar_t *corewar, champions_t *champion)
{
    int *parameters = get_parameters(corewar->memory, champion->program->pc);

    if (check_parameters(parameters, 3) == false)
        return;
    if (parameters[2] == T_REG)
        champion->program->reg[parameters[3]] =
        champion->program->reg[parameters[1]];
    if (parameters[2] == T_IND)
        corewar->memory[(champion->program->pc + parameters[3]
        % IDX_MOD) % MEM_SIZE] = champion->program->reg[parameters[1]];
}