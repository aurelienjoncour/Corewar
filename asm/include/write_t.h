/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_t
*/

#ifndef WRITE_T_H_
#define WRITE_T_H_

#include "parser_t.h"

typedef struct {
    int fd;
    token_t **array;
    int idx_mnemonique;
    bool is_it_index;
}write_t;

#endif /* !WRITE_T_H_ */
