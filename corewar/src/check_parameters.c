/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Check paramters
*/

#include "corewar.h"

bool check_parameters(unsigned int *parameters, int mnemonic)
{
    op_t op = op_tab[mnemonic - 1];

    if (parameters == NULL)
        return false;
    if (parameters[op.nbr_args * 2] != 0)
        return false;
    for (int i = 0; i < op.nbr_args; i++) {
        if (parameters[i * 2] == T_REG && (parameters[i * 2 + 1] > REG_NUMBER
        || parameters[i * 2 + 1] == 0))
            return false;
        if ((parameters[i * 2] & op.type[i]) == 0)
            return false;
    }
    return true;
}