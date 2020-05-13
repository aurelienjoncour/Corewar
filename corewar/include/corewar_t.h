/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar_t
*/

#ifndef COREWAR_T_H_
#define COREWAR_T_H_

#include "champions_t.h"
#include "op.h"

typedef struct {
    unsigned char *memory;
    champions_t **array;
    int nbr_cycle;
    int nbr_live;
}corewar_t;



#endif /* !COREWAR_T_H_ */
