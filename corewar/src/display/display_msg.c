/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** display_msg
*/

#include "corewar.h"

void live_msg(champions_t *champion)
{
    my_putstr("The player ");
    my_put_nbr(champion->prog_number);
    my_putstr(" (");
    my_putstr(champion->head->prog_name);
    my_putstr(") is alive.\n");
}

void won_msg(champions_t *champion)
{
    my_putstr("The player ");
    my_put_nbr(champion->prog_number);
    my_putstr(" (");
    my_putstr(champion->head->prog_name);
    my_putstr(") won.\n");
}