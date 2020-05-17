/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** champions_t
*/

#ifndef CHAMPIONS_T_H_
#define CHAMPIONS_T_H_

#include "program_t.h"

typedef struct {
    int load_address;
    int prog_number;
    char *filepath;
    header_t *head;
    unsigned char *data;
    program_t *program;
    int cycle;
}champions_t;


#endif /* !CHAMPIONS_T_H_ */
