/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Get parameters
*/

#include "corewar.h"

static int get_mnemonic(unsigned char *memory, size_t pc)
{
    char *mnemonic_str = my_putnbr_base_in_str(memory[pc], "0123456789");
    int mnemonic = my_getnbr(mnemonic_str);

    free(mnemonic_str);
    return mnemonic;
}

/*static int get_value(unsigned char *memory, size_t adress, size_t size)
{
    char *value = malloc(sizeof(char) * (size * 2 + 1));
    char *str = NULL;
    int value = 0;

    value[0] = '\0';
    for (size_t i = 0; i < size; i++) {
        str = my_putnbr_base_in_str(memory[adress], "0123456789ABCDEF");
        value = my_strcat(value, str);
        adress++;
        free(str);
    }
    str = my_putnbr_base_in_str(value, "0123456789");
    value = my_getnbr(str);
    free(str);
    return value;
}*/

static int get_value(unsigned char *memory, size_t adress, size_t size)
{
    int value = 0;
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

static void get_parameters_type(unsigned char par_types, int *parameters)
{
    char *par_types_in_binary = my_putnbr_base_in_str(par_types, "01");

    for (size_t i = 0; i < 4; i++) {
        if (my_strcmp(par_types_in_binary[i * 2], "01") == 0)
            parameters[i * 2] = T_REG;
        if (my_strcmp(par_types_in_binary[i * 2], "10") == 0)
            parameters[i * 2] = T_DIR;
        if (my_strcmp(par_types_in_binary[i * 2], "11") == 0)
            parameters[i * 2] = T_IND; 
    }
}

static int get_parameters_values(unsigned char *memory, size_t adress,
int *parameters, int mnemonic)
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

int *get_parameters(unsigned char *memory, size_t pc)
{
    int *parameters = malloc(sizeof(int) * 8);
    int mnemonic = get_mnemonic(memory, pc);

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