/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

char const *ACT[] = {
    "live",
    "ld",
    "st",
    "add",
    "sub",
    "and",
    "or",
    "xor",
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lld",
    "lldi",
    "lfork",
    "aff",
    NULL,
    };

static ssize_t check_act(char **line)
{
    for (ssize_t bis = 0; ACT[bis]; bis++) {
        if (my_strcmp(line[0], ACT[bis]) == 0) {
            //write in file
            return bis;
        }
    }
    return -1;
}

bool compile_file(char **file)
{
    char **parth;

    for (size_t y = 0; file[y]; y++) {
        parth = my_str_to_word_array(file[y], "\t ");
        if (!parth)
            return false;
        if (check_act(parth) == -1) {
            destroy_file(parth);
            return false;
        }
        destroy_file(parth);
    }
    return true;
}