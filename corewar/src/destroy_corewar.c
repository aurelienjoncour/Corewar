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
    for (size_t i = 0; corewar->array[i] != NULL &&
        corewar->array[i]->filepath != NULL; i++) {
        free(corewar->array[i]->filepath);
        free(corewar->array[i]->head);
        if (corewar->array[i]->program != NULL)
            free(corewar->array[i]->program->reg);
        free(corewar->array[i]->program);
        free(corewar->array[i]->data);
    }
    free(corewar->array);
}