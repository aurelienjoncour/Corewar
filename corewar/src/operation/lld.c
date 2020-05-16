/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Long Load Operation
*/

#include "corewar.h"

static void update_carry(unsigned int value, champions_t *champion)
{
    if (value == 0)
        champion->program->carry = 1;
    else
        champion->program->carry = 0;
}

int lld(corewar_t *corewar, champions_t *champion)
{
    size_t address = 0;
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (parameters == NULL)
        return EXIT_ERROR;
    if (!check_parameters(parameters, 13))
        return EXIT_FAILURE;
    if (parameters[0] == T_DIR) {
        champion->program->reg[parameters[3] - 1] = parameters[1];
    } else if (parameters[0] == T_IND){
        address = champion->program->pc + parameters[1] % MEM_SIZE;
        champion->program->reg[parameters[3] - 1] =
        get_int_in_memory(corewar->memory, address);
    }
    update_carry(champion->program->reg[parameters[3] - 1], champion);
    free(parameters);
    return EXIT_SUCCESS;
}