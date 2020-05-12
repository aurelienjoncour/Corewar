/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Add Operation
*/

#include "corewar.h"

void add(corewar_t *corewar, champions_t *champs)
{
    int *param = get_parameters(corewar->memory, champion->program->pc);

    champ->program->reg[param[2]] =
    champ->program->reg[param[1]] + champ->program->reg[param[0]];
    //CARRY
    free(param);
}