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
    short index = 0;

    if (parameters == NULL)
        return EXIT_ERROR;
    if (!check_parameters(parameters, 9))
        return EXIT_FAILURE;
    index = parameters[1];
    if (champion->program->carry) {
        champion->program->pc = champion->program->pc + index % IDX_MOD;
        champion->program->pc = champion->program->pc % MEM_SIZE;
    }
    free(parameters);
    return EXIT_SUCCESS;
}