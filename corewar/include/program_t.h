/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** program_t
*/

#ifndef PROGRAM_T_H_
#define PROGRAM_T_H_

#include <stdlib.h>

typedef struct program {
    size_t pc;
    unsigned int *reg;
    int carry;
    int live;
} program_t;


#endif /* !PROGRAM_T_H_ */
