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
#include "champions_t.h"
#include "corewar_t.h"
#include "parser_t.h"

#define BIT_LINE 32
#define PC champion->program->pc

typedef int (*fct_ptr)(corewar_t *, champions_t *);


int usage(char *binary, int status);
bool allow_char(char *script, char *allow_char);

int get_argument(int ac, char **av, corewar_t *corewar);
int dump_flag(int *i, char **av, corewar_t *corewar, size_t *index);
int number_flag(int *i, char **av, corewar_t *corewar, size_t *index);
int load_flag(int *i, char **av, corewar_t *corewar, size_t *index);
int champs_flag(int *i, char **av, corewar_t *corewar, size_t *index);

unsigned char *create_memory(void);
program_t *create_program(int nb_of_player, size_t load_adress);
void display_pointeur_tab(size_t i, size_t max);
bool attribut_number(champions_t **champ);
bool attribut_memory(champions_t **champ);

int read_file(champions_t *champions);
int init_corewar(corewar_t *corewar);
void destroy_corewar(corewar_t *corewar);
int init_champions(corewar_t *corewar);

void write_data_on_mem(corewar_t *corewar, champions_t *champion);
//Display

unsigned int *get_parameters(unsigned char *memory, size_t pc);
bool check_parameters(unsigned int *parameters, int mnemonic);

void live_msg(champions_t *champion);
void won_msg(champions_t *champion);
void display_memory(unsigned char *memory);

champions_t **sort_champions(corewar_t *cw);
champions_t **realloc_champion_array(champions_t **array);
int nb_champions(champions_t **array);
bool verify_sort(champions_t **arr, int nb);

int loop(corewar_t *corewar);
void update_pc(corewar_t *corewar, champions_t *champion);

int live(corewar_t *corewar, champions_t *champion);
int ld(corewar_t *corewar, champions_t *champion);
int st(corewar_t *corewar, champions_t *champion);
int add(corewar_t *corewar, champions_t *champion);
int sub(corewar_t *corewar, champions_t *champion);
int and_instruction(corewar_t *corewar, champions_t *champion);
int or(corewar_t *corewar, champions_t *champion);
int xor(corewar_t *corewar, champions_t *champion);
int zjmp(corewar_t *corewar, champions_t *champion);
int ldi(corewar_t *corewar, champions_t *champion);
int sti(corewar_t *corewar, champions_t *champion);
int fork_instruction(corewar_t *corewar, champions_t *champion);
int lld(corewar_t *corewar, champions_t *champion);
int lldi(corewar_t *corewar, champions_t *champion);
int lfork(corewar_t *corewar, champions_t *champion);
int aff(corewar_t *corewar, champions_t *champion);

void write_int_in_mem(unsigned char *memory, size_t adress,
unsigned int number);
bool is_index_type(char code);
unsigned int get_int_in_memory(unsigned char *memory, size_t adress);
unsigned int get_short_in_memory(unsigned char *memory, size_t adress);

int nb_death(corewar_t *corewar);
int check_dead(corewar_t *corewar);

#endif /* !COREWAR_H_ */
