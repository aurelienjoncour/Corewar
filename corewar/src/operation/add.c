/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Add Operation
*/

#include "corewar.h"

void add(corewar_t *corewar, champions_t *champion)
{
    int *param = get_parameters(corewar->memory, PC);

    champion->program->reg[param[2]] =
    champion->program->reg[param[1]] + champion->program->reg[param[0]];
    //CARRY
    free(param);
}