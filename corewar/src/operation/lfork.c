/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Long Fork Operation
*/

#include "corewar.h"

static int dup_program(champions_t *champion, champions_t **array, int nb)
{
    array[nb]->program = malloc(sizeof(program_t));
    if (array[nb]->program == NULL)
        return EXIT_ERROR;
    array[nb]->program->pc = champion->program->pc;
    array[nb]->program->carry = champion->program->carry;
    array[nb]->program->live = champion->program->live;
    array[nb]->program->reg = malloc(REG_SIZE * REG_NUMBER);
    if (champion->program->reg == NULL)
        return EXIT_ERROR;
    for (size_t i = 0; i < REG_NUMBER; i++)
        array[nb]->program->reg[i] = champion->program->reg[i];
    return EXIT_SUCCESS;
}

static int dup_champions(champions_t *champion, champions_t **array)
{
    int nb = nb_champions(array);

    array[nb] = malloc(sizeof(champions_t));
    if (array[nb] == NULL)
        return EXIT_ERROR;
    array[nb]->load_address = champion->load_address;
    array[nb]->prog_number = champion->prog_number;
    array[nb]->filepath = my_strdup(champion->filepath);
    array[nb]->head = malloc(sizeof(header_t));
    if (array[nb]->head == NULL)
        return EXIT_ERROR;
    read_file(array[nb]);
    if (dup_program(champion, array, nb) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int apply_change(unsigned int *parameters, corewar_t *corewar)
{
    short index = 0;
    char mnemonique = 0;

    index = parameters[1];
    corewar->array[nb_champions(corewar->array) - 1]->program->pc += index;
    mnemonique = corewar->memory[
    corewar->array[nb_champions(corewar->array) - 1]->program->pc % MEM_SIZE];
    if (mnemonique >= 0 && mnemonique <= 16)
        corewar->array[nb_champions(corewar->array) - 1]->program->wait_time =
        op_tab[mnemonique - 1].nbr_cycles;
    corewar->array[nb_champions(corewar->array) - 1]->cycle =
    corewar->current_cycle;
    return EXIT_SUCCESS;
}

int lfork(corewar_t *corewar, champions_t *champion)
{
    unsigned int *parameters = get_parameters(corewar->memory, PC);

    if (parameters == NULL)
        return EXIT_ERROR;
    if (check_parameters(parameters, 12) == false)
        return EXIT_FAILURE;
    corewar->array = realloc_champion_array(corewar->array);
    if (dup_champions(champion, corewar->array) == EXIT_ERROR)
        return EXIT_ERROR;
    apply_change(parameters, corewar);
    free(parameters);
    return EXIT_SUCCESS;
}