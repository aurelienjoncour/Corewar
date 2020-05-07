/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Sti Operation
*/

#include "corewar.h"

void sti(int *reg, int value1, int value2, int *pc)
{
    int *adress = pc + value1 + value2;

    adress = *reg;
}