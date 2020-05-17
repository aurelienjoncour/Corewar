/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Loop
*/

#include "corewar.h"

static int (*instruction_ptr[])(corewar_t *, champions_t *) = {
    &live,
    &ld,
    &st,
    &add,
    &sub,
    &and_instruction,
    &or,
    &xor,
    &zjmp,
    &ldi,
    &sti,
    &fork_instruction,
    &lld,
    &lldi,
    &lfork,
    &aff
};

int instruction(corewar_t *corewar, champions_t *champion)
{
    int ret = 0;
    char mnemonic = corewar->memory[champion->program->pc % MEM_SIZE];

    if (mnemonic < 1 || mnemonic > 16) {
        champion->program->pc++;
        return EXIT_FAILURE;
    }
    if (champion->cycle + champion->program->wait_time ==
        corewar->current_cycle) {
        ret = instruction_ptr[mnemonic - 1](corewar, champion);
        if (ret != EXIT_SUCCESS)
            return ret;
        if (mnemonic != 9)
            update_pc(corewar, champion);
        champion->cycle = corewar->current_cycle;
        mnemonic = corewar->memory[champion->program->pc % MEM_SIZE];
        if (mnemonic >= 1 && mnemonic <= 16)
            champion->program->wait_time = op_tab[mnemonic - 1].nbr_cycles;
    }
    return EXIT_SUCCESS;
}

int compute_instruction(corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);

    for (int i = 0; i < nb; i++) {
        if (corewar->array[i]->program->live != -1)
            if (instruction(corewar, corewar->array[i]) == EXIT_ERROR)
                return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int init_wait_time(corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);
    char mnemonique = 0;

    for (int i = 0; i < nb; i++) {
        mnemonique = corewar->memory[corewar->array[i]->program->pc % MEM_SIZE];
        if (mnemonique >= 0 && mnemonique <= 16) {
            corewar->array[i]->program->wait_time =
            op_tab[mnemonique - 1].nbr_cycles;
            corewar->array[i]->cycle = 0;
        }
    }
    return EXIT_SUCCESS;
}

int check_dead(corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);
    int dead = 0;

    for (int i = 0; i < nb; i++) {
        if (!corewar->array[i]->program->live) {
            corewar->array[i]->program->live = -1;
        }
        if (corewar->array[i]->program->live != -1) {
            corewar->array[i]->program->live = 0;
        }
    }
    for (int i = 0; i < nb; i++) {
        if (corewar->array[i]->program->live == -1)
            dead++;
    }
    if (dead == nb - 1 || dead == nb)
        return true;
    return false;
}

int loop(corewar_t *corewar)
{
    int cnt = 0;

    init_wait_time(corewar);
    for (; true; corewar->current_cycle++) {
        if (compute_instruction(corewar) == EXIT_ERROR)
            return EXIT_ERROR;
        if (cnt >= corewar->nbr_cycle_to_die) {
            cnt = 0;
            if (check_dead(corewar))
                break;
        }
        if (corewar->current_cycle == corewar->nbr_cycle)
            display_memory(corewar->memory);
        cnt++;
    }
    if (corewar->last_alive) {
        won_msg(corewar->array[corewar->last_alive - 1]);
    } else {
        my_putstr("Nobody survived...\n");
    }
    return EXIT_SUCCESS;
}
