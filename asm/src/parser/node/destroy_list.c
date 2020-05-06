/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** destroy_list
*/

#include "corewar.h"

void destroy_list(token_t *ptr)
{
    free(ptr->token);
    if (ptr->prev != NULL)
        free(ptr->prev);
    if (ptr->next != NULL) {
        destroy_list(ptr->next);
    } else {
        free(ptr);
    }
}