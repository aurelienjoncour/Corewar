/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** display_list
*/

#include "corewar.h"

void display_list(token_t *start)
{
    if (start == NULL)
        return;
    my_putstr(start->token);
    my_putstr("\n");
    if (start->next != NULL)
        display_list(start->next);
}
