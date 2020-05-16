/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Loop
*/

#include "corewar.h"

static bool check_if_champion_are_alive(corewar_t *corewar)
{
    int prog_alive = 0;

    for (size_t i = 0; corewar->array[i]; i++) {
        if (corewar->array[i]->filepath == NULL)
            continue;
        if (corewar->array[i]->program->live == 0)
            corewar->array[i]->program->live = -1;
        if (corewar->array[i]->program->live == 1)
            prog_alive += 1;
    }
    if (prog_alive == 0)
        return false;
    return true;
}

static void get_wait_time(corewar_t *corewar, champions_t *champion)
{
    int mnemonic = corewar->memory[champion->program->pc];

    champion->program->wait_time = op_tab[mnemonic - 1].nbr_cycles;
}

static void make_instruction(corewar_t *corewar, champions_t *champion,
int *last_alive)
{
    int (*instruction_ptr[])(corewar_t *, champions_t *) = {&live, &ld, &st,
    &add, &sub, &and_instruction, &or, &xor, &zjmp, &ldi, &sti,
    &fork_instruction, &lld, &lldi, &lfork, &aff};
    int mnemonic = corewar->memory[champion->program->pc];

    if (mnemonic >= 1 && mnemonic <= 16) {
        if (instruction_ptr[mnemonic - 1](corewar, champion) == EXIT_ERROR)
            champion->program->pc = -1;
        return;
    }
    if (mnemonic != 1) {
        champion->program->pc = -1;
        return;
    }
    for (size_t i = 0;corewar->array[i]; i++) {
        if (corewar->array[i]->prog_number ==
        corewar->memory[champion->program->pc + 1]) {
            live_msg(corewar->array[i]);
            *last_alive = corewar->memory[champion->program->pc + 1];
        }
    }
}

static void check_instruction(corewar_t *corewar, int *last_alive)
{
    int nb = nb_champions(corewar->array);

    for (int i = 0; i < nb; i++) {
        if (corewar->array[i]->filepath == NULL)
            continue;
        if (corewar->array[i]->program->live == -1)
            continue;
        if (corewar->array[i]->program->pc == -1)
            continue;
        if (corewar->array[i]->program->wait_time <= 0)
            get_wait_time(corewar, corewar->array[i]);
        if (corewar->array[i]->program->wait_time == 1) {
            make_instruction(corewar, corewar->array[i], last_alive);
            update_pc(corewar, corewar->array[i]);
        }
        corewar->array[i]->program->wait_time -= 1;
    }
}

void loop(corewar_t *corewar)
{
    int last_alive = -1;

    if (nb_champions(corewar->array) < 2)
        return;
    while (1 == 1) {
        if (corewar->current_cycle == corewar->nbr_cycle)
            display_memory(corewar->memory);
        check_instruction(corewar, &last_alive);
        if (corewar->current_cycle == CYCLE_TO_DIE - (CYCLE_DELTA *
        (corewar->current_cycle / NBR_LIVE))) {
            corewar->current_cycle = 0;
            if (check_if_champion_are_alive(corewar) == false)
                break;
        }
        corewar->current_cycle += 1;
    }
    for (size_t i = 0; corewar->array[i]; i++) {
        if (corewar->array[i]->prog_number == last_alive)
            won_msg(corewar->array[i]);
    }
}