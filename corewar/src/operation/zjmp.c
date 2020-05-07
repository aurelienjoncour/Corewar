/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Zjmp Operation
*/

#include "corewar.h"

void zjmp(int *pc, int carry, int *index)
{
    if (carry == 1)
        *pc = *index;
}