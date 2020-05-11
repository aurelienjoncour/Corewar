/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parser_t
*/

#ifndef PARSER_T_H_
#define PARSER_T_H_

#include "corewar_t.h"

typedef struct {
    char *flag;
    int (*fct)(int *i, char **av, corewar_t *corewar, size_t *index);
}parser_t;

#endif /* !PARSER_T_H_ */
