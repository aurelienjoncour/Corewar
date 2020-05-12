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

    corewar->memory[param[2] % MEM_SIZE] = param[0] - param[1];
    //CARRY
    free(param);
}