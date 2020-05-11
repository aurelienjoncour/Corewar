/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "constant.h"
#include "champions_t.h"
#include "corewar_t.h"
#include "parser_t.h"

int usage(char *binary, int status);
bool allow_char(char *script, char *allow_char);
int get_argument(int ac, char **av, corewar_t *corewar);

int dump_flag(int *i, char **av, corewar_t *corewar, size_t *index);
int number_flag(int *i, char **av, corewar_t *corewar, size_t *index);
int load_flag(int *i, char **av, corewar_t *corewar, size_t *index);
int champs_flag(int *i, char **av, corewar_t *corewar, size_t *index);

#endif /* !COREWAR_H_ */
