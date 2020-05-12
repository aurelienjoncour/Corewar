/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Sub Operation
*/

#include "corewar.h"

void sub(corewar_t *corewar, champions_t *champs)
{
    int *param = get_parameters(corewar->memory, champion->program->pc);

    champ->program->reg[param[2]] =
    champ->program->reg[param[0]] - champ->program->reg[param[1]];
    //CARRY
    free(param);
}