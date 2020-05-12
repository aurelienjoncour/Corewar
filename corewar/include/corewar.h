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

typedef struct program_s {
    size_t pc;
    int *reg;
    int carry;
    int live;
    char *name;
} program_t;

data_read_t read_file(char *path);
void display_memory(unsigned char *memory);
unsigned char *create_memory(void);
program_t *create_program(int nb_of_player, char *name_of_player,
size_t load_adress);
unsigned char *write_data_on_mem(unsigned char *mem, int adr,
data_read_t *file);
void display_pointeur_tab(size_t i, size_t max);
void attribut_number(champions_t *champ);
bool attribut_memory(champions_t *champ);
void attribut_memory_no_flag(champions_t *champ);

#endif /* !COREWAR_H_ */
