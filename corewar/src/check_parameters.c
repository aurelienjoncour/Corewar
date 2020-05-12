/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Check paramters
*/

#include "corewar.h"

bool check_parameters(int *parameters, int mnemonic)
{
    op_t op = op_tab[mnemonic - 1];

    if (parameters[op.nbr_args * 2] != 0)
        return false;
    for (size_t i = 0; i < op.nbr_args; i++) {
        if (parameters[i * 2] == T_REG && parameters[i * 2 + 1] > REG_NUMBER)
            return false;
        if (parameters[i * 2] & op.type[i] == 0)
            return false;
    }
    return true;
}