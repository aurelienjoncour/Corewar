/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Update the pc
*/

#include "corewar.h"

void update_pc(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = NULL;
    int mnemonic = corewar->memory[PC];

    if (champion->program->pc == -1)
        return;
    parameters = get_parameters(corewar->memory, PC);
    champion->program->pc += 1;
    if (mnemonic != 1 && mnemonic != 12 && mnemonic != 15 && mnemonic != 9)
        champion->program->pc += 1;
    for (size_t i = 0; parameters[i * 2] != 0; i++) {
        if (parameters[i * 2] == T_REG)
            champion->program->pc += 1;
       if (parameters[i * 2] == T_IND ||
            (parameters[i * 2] == T_DIR && is_index_type(mnemonic))) {
            champion->program->pc += 2;
        } else if (parameters[i * 2] == T_DIR)
            champion->program->pc += 4;
    }
}