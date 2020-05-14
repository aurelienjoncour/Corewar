/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Zjmp Operation
*/

#include "corewar.h"

int zjmp(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (!check_parameters(parameters, 9) || champion->program->carry != 1)
        return -1;
    champion->program->pc += parameters[1] % IDX_MOD;
    champion->program->pc %= MEM_SIZE;
    free(parameters);
    return 1;
}