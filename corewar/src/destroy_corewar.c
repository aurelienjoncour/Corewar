/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** destroy_corewar
*/

#include "corewar.h"

void destroy_corewar(corewar_t *corewar)
{
    free(corewar->memory);
    for (size_t i = 0; i < MAX_NB_CHAMPIONS &&
        corewar->array[i].filepath != NULL; i++) {
            free(corewar->array[i].filepath);
            free(corewar->array[i].head);
            free(corewar->array[i].program->reg);
            free(corewar->array[i].program);
            free(corewar->array[i].data);
        }
}