/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <endian.h>
#include "my.h"
#include "op.h"
#include "constant.h"
#include "struct.h"

#define BIT_LINE 32
#define SPACE ' '

typedef struct program_s {
    size_t pc;
    int *reg;
    int carry;
    int live;
    char *name;
} program_t;

int usage(char *binary, int status);
data_read_t read_file(char *path);
void display_memory(unsigned char *memory);
unsigned char *create_memory(void);
program_t *create_program(int nb_of_player, char *name_of_player,
size_t load_adress);
unsigned char *write_data_on_mem(unsigned char *mem, int adr,
data_read_t *file);
void display_pointeur_tab(size_t i, size_t max);

#endif /* !COREWAR_H_ */
