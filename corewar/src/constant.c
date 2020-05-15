/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** constant
*/

#include "corewar.h"

const int EXIT_ERROR = 84;

const parser_t flags[] = {
    {"-dump", dump_flag},
    {"-n", number_flag},
    {"-a", load_flag},
    {NULL, NULL}
};

const char index_list[] = {9, 10, 11, 12, 14, 15, 0};