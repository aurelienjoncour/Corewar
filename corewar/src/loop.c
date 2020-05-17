/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Loop
*/

#include "corewar.h"

static fct_ptr tab_inst[] = {
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
        ret = tab_inst[mnemonic - 1](corewar, champion);
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
    char code = 0;

    for (int i = 0; i < nb; i++) {
        code = corewar->memory[corewar->array[i]->program->pc % MEM_SIZE];
        if (code >= 0 && code <= 16) {
            corewar->array[i]->program->wait_time =
            op_tab[code - 1].nbr_cycles;
            corewar->array[i]->cycle = 0;
        }
    }
    return EXIT_SUCCESS;
}

int end_msg(corewar_t *corewar)
{
    int nb = nb_champions(corewar->array);
    int death = nb_death(corewar);

    if (!corewar->last_alive) {
        my_putstr("Nobody survived...\n");
    } else if (death == nb) {
        won_msg(corewar->array[0]);
    } else {
        won_msg(corewar->array[corewar->last_alive - 1]);
    }
    return EXIT_SUCCESS;
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
        if (corewar->current_cycle == corewar->nbr_cycle) {
            display_memory(corewar->memory);
            break;
        }
        cnt++;
    }
    end_msg(corewar);
    return EXIT_SUCCESS;
}
