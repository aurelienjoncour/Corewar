/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Sti Operation
*/

#include "corewar.h"

int sti(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);
    size_t address = 0;

    if (parameters == NULL)
        return EXIT_ERROR;
    if (check_parameters(parameters, 11) == false)
        return EXIT_FAILURE;
    for (size_t i = 2; i < 6; i += 2) {
        if (parameters[i] == T_REG)
            address += champion->program->reg[parameters[i + 1] - 1];
        if (parameters[i] == T_DIR)
            address += parameters[i + 1];
        if (parameters[i] == T_IND)
            address += get_short_in_memory(corewar->memory,
                        (PC + parameters[i + 1]) % MEM_SIZE);
    }
    write_int_in_mem(corewar->memory, (PC + (address % IDX_MOD) % MEM_SIZE),
    champion->program->reg[parameters[1] - 1]);
    free(parameters);
    return EXIT_SUCCESS;
}