/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Ldi Operation
*/

#include "corewar.h"

void ldi(short index1, short index2, int *reg, int *pc)
{
    int *adress = pc + (index1 + index2) % IDX_MOD;

    *reg = *adress;
    //CARRY
}