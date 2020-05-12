/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Create program
*/

#include "corewar.h"

program_t *create_program(int nb_of_player, size_t load_adress)
{
    program_t *program = malloc(sizeof(program_t));

    if (program == NULL)
        return NULL;
    program->pc = load_adress;
    program->reg = malloc(REG_SIZE * REG_NUMBER);
    if (program->reg == NULL)
        return NULL;
    program->reg[0] = nb_of_player;
    for (size_t i = 1; i < REG_NUMBER; i++)
        program->reg[i] = 0;
    program->carry = 0;
    program->live = 0;
    return program;
}