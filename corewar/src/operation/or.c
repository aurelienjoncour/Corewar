/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Or Operation
*/

#include "corewar.h"

static char find_digit(char *binary_value, int i, int *pos)
{
    if (my_strlen(binary_value) >= REG_SIZE - i) {
        *pos += 1;
        return binary_value[*pos - 1];
    }
    return '0';
}

static char make_or(char digit0, char digit1)
{
    if (digit0 == '1' || digit1 == '1')
        return '1';
    return '0';
}

void or_operation(int value1, int value2, int *reg)
{
    char *binary_value1 = my_putnbr_base_in_str(value1, "01");
    char *binary_value2 = my_putnbr_base_in_str(value2, "01");
    char binary_result[5];
    char *result;
    char digit[2];
    int pos[] = {0, 0};

    binary_result[8] = '\0';
    for (int i = 0; i < REG_SIZE; i++) {
        digit[0] = find_digit(binary_value1, i, &pos[0]);
        digit[1] = find_digit(binary_value2, i, &pos[1]);
        binary_result[i] = make_or(digit[0], digit[1]);
    }
    result = my_putnbr_base_in_str(my_getnbr(binary_result), "0123456789");
    *reg = my_getnbr(result);
    free(result);
    free(binary_value1);
    free(binary_value2);
    //CARRY
}