/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Live Operation
*/

#include "corewar.h"

void live(int player_nb, char *player_name)
{
    my_putstr("The player ");
    my_put_nbr(player_nb);
    my_putstr("(");
    my_putstr(player_name);
    my_putstr(")is alive");
}