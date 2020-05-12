/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** And Operation
*/

#include "corewar.h"

void and_instruction(corewar_t *corewar, champions_t *champion)
{
    int *parameters = get_parameters(corewar->memory, champion->program->pc);
    int values[] = {0, 0};

    if (check_parameters(parameters, 6) == false)
        return;
    for (size_t i = 0; i < 2; i++) {
        if (parameters[i * 2] == T_REG)
            values[i] = champion->program->reg[parameters[i * 2 + 1]];
        if (parameters[i * 2] == T_DIR)
            values[i] = parameters[i * 2 + 1];
        if (parameters[i * 2] == T_IND)
            values[i] = corewar->memory[
            (champion->program->pc + parameters[i * 2 + 1]
            % IDX_MOD) % MEM_SIZE];
    }
    champion->program->reg[parameters[5]] = values[0] & values[1];
    if (champion->program->reg[parameters[5]] == 0)
        champion->program->carry = 1;
    else
        champion->program->carry = 0;
}