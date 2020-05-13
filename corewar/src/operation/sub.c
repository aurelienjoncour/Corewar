/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Sub Operation
*/

#include "corewar.h"

void sub(corewar_t *corewar, champions_t *champion)
{
    int *param = get_parameters(corewar->memory, PC);

    if (check_parameters(param, 5) == false)
        return;
    champion->program->reg[param[5]] =
    champion->program->reg[param[1]] - champion->program->reg[param[3]];
    //CARRY ?
    free(param);
}