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
            value += memory[adress] << values[i];
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
        if (parameters[i * 2] == T_DIR ||
        (parameters[i * 2] == T_IND && (mnemonic == 10 || mnemonic == 11 ||
        mnemonic == 12 || mnemonic == 14 || mnemonic == 15))) {
            parameters[i * 2 + 1] = get_value(memory, adress, 2);
            adress += 2;
            continue;
        }
        if (parameters[i * 2] == T_IND) {
            parameters[i * 2 + 1] = get_value(memory, adress, 4);
            adress += 4;
        }
    }
}

unsigned int *get_parameters(unsigned char *memory, size_t pc)
{
    unsigned int *parameters = malloc(sizeof(unsigned int) * 8);
    int mnemonic = memory[pc];

    if (parameters == NULL)
        return NULL;
    for (size_t i = 0; i < 8; i++)
        parameters[i] = 0;
    if (mnemonic == 1 || mnemonic == 12 || mnemonic == 15 || mnemonic == 9) {
        parameters[0] = T_DIR;
        parameters[1] = get_value(memory, pc + 1, 2);
    } else {
        get_parameters_type(memory[pc + 1], parameters);
        get_parameters_values(memory, pc + 2, parameters, mnemonic);
    }
    return parameters;
}