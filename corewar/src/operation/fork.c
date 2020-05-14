/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Fork Operation
*/

#include "corewar.h"

static void dup_champions(champions_t *champion, champions_t *new_champion)
{
    new_champion = malloc(sizeof(champions_t));
    new_champion->load_address = champion->load_address;
    new_champion->prog_number = champion->prog_number;
    new_champion->filepath = my_strdup(champion->filepath);
    new_champion->head = malloc(sizeof(header_t));
    read_file(new_champion);
    new_champion->program = malloc(sizeof(program_t));
    new_champion->program->pc = champion->program->pc;
    new_champion->program->carry = champion->program->carry;
    new_champion->program->live = new_champion->program->live;
    new_champion->program->wait_time = -1;
    new_champion->program->reg = malloc(REG_SIZE * REG_NUMBER);
    for (size_t i = 0; i < REG_NUMBER; i++)
        new_champion->program->reg = champion->program->reg;
}

void fork_instruction(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (check_parameters(parameters, 12) == false)
        return;
    corewar->array = realloc_champion_array(corewar->array);
    dup_champions(champion, corewar->array[nb_champions(corewar->array) + 1]);
    corewar->array[nb_champions(corewar->array) + 1]->program->pc +=
    parameters[1] % IDX_MOD;
    free(parameters);
}