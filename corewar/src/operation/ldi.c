/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Ldi Operation
*/

#include "corewar.h"

static void update_carry(unsigned int value, champions_t *champion)
{
    if (value == 0)
        champion->program->carry = 1;
    else
        champion->program->carry = 0;
}

static void do_ldi(unsigned int *parameters, corewar_t *corewar,
champions_t *champion, size_t addres)
{
    champion->program->reg[parameters[5] - 1] =
    get_int_in_memory(corewar->memory, (PC + addres % IDX_MOD) % MEM_SIZE);
    update_carry(champion->program->reg[parameters[5] - 1], champion);

}

int ldi(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);
    size_t addres = 0;

    if (parameters == NULL)
        return EXIT_ERROR;
    if (!check_parameters(parameters, 10))
        return EXIT_FAILURE;
    for (size_t i = 0; i < 4; i += 2) {
        if (parameters[i] == T_REG)
            addres += champion->program->reg[parameters[i + 1] - 1];
        if (parameters[i] == T_DIR)
            addres += parameters[i + 1];
        if (parameters[i] == T_IND)
            addres += get_short_in_memory(corewar->memory,
                        PC + parameters[i + 1] % IDX_MOD);
    }
    do_ldi(parameters, corewar, champion, addres);
    free(parameters);
    return EXIT_SUCCESS;
}