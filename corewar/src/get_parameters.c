/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Get parameters
*/

#include "corewar.h"

static unsigned int get_value(unsigned char *memory, size_t adress,
size_t size)
{
    unsigned int value = 0;
    int values[] = {24, 16, 8, 0};

    for (size_t i = 0; i < 4; i++) {
        if (i + size >= 4) {
            value += memory[adress % MEM_SIZE] << values[i];
            adress++;
        } else
            value += 0 << values[i];
    }
    return value;
}

static void get_parameters_type(unsigned char par_types,
unsigned int *parameters)
{
    for (size_t i = 0; i < 8; i += 2) {
        parameters[i] = par_types >> (6 - i);
        par_types -= parameters[i] << (6 - i);
        if (parameters[i] == 3)
            parameters[i] = T_IND;
    }
}

static void get_parameters_values(unsigned char *memory, size_t adress,
unsigned int *parameters, int mnemonic)
{
    for (size_t i = 0; i < 4; i++) {
        if (parameters[i * 2] == T_REG) {
            parameters[i * 2 + 1] = get_value(memory, adress, 1);
            adress += 1;
        }
        if (parameters[i * 2] == T_IND ||
            (parameters[i * 2] == T_DIR && is_index_type(mnemonic))) {
            parameters[i * 2 + 1] = get_value(memory, adress, 2);
            adress += 2;
        } else if (parameters[i * 2] == T_DIR) {
            parameters[i * 2 + 1] = get_value(memory, adress, 4);
            adress += 4;
        }
    }
}

static size_t get_size_params(char mnemonic)
{
    size_t nb_bytes = 0;

    if (is_index_type(mnemonic)) {
        nb_bytes = 2;
    } else {
        nb_bytes = 4;
    }
    return nb_bytes;
}

unsigned int *get_parameters(unsigned char *memory, size_t pc)
{
    unsigned int *parameters = malloc(sizeof(unsigned int) * 8);
    char mnemonic = memory[pc];
    size_t nb_bytes = get_size_params(mnemonic);

    if (parameters == NULL)
        return NULL;
    for (size_t i = 0; i < 8; i++)
        parameters[i] = 0;
    if (mnemonic == 1 || mnemonic == 9 || mnemonic == 12 || mnemonic == 15 ) {
        parameters[0] = T_DIR;
        parameters[1] = get_value(memory, pc + 1, nb_bytes);
    } else {
        get_parameters_type(memory[(pc + 1) % MEM_SIZE], parameters);
        get_parameters_values(memory, pc + 2, parameters, mnemonic);
    }
    return parameters;
}