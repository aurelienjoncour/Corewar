/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Aff Operation
*/

#include "corewar.h"

int aff(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (check_parameters(parameters, 2) == false)
        return -1;
    my_putchar(champion->program->reg[parameters[1]] % 256);
    free(parameters);
    return 1;
}