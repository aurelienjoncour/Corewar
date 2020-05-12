/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Load Operation
*/

#include "corewar.h"

void ld(corewar_t *corewar, champions_t *champion)
{
    int *parameters = get_parameters(corewar->memory, champion->program->pc);

    if (check_parameters(parameters, 2) == false)
        return;
    if (parameters[0] == T_DIR)
        champion->program->reg[parameters[3]] = parameters[1];
    if (parameters[0] == T_IND)
        champion->program->reg[parameters[3]] =
        corewar->memory[(champion->program->pc + parameters[1]) % IDX_MOD];
    //CARRY
}