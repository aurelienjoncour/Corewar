/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_instruction
*/

#include "corewar.h"

static int write_first_part(int fd, token_t *token, int *index)
{
    token_t *tmp = token;
    unsigned char byte = 0;

    if (tmp->next->id == ID_LABEL) {
        if (tmp->next->next == NULL)
            return EXIT_SUCCESS;
        tmp = tmp->next->next->next;
    }
    *index = find_index_op(tmp->token);
    write(fd, &op_tab[*index].code, sizeof(char));
    if (op_tab[*index].nbr_args != 1 || op_tab[*index].code == 16) {
       byte = get_description_params(tmp);
       write(fd, &byte, sizeof(char));
    }
    return EXIT_SUCCESS;
}

static void write_indirect(token_t *tmp, int fd)
{
    short two_bytes = 0;

    if (tmp->prev->id == ID_LABEL) {
        two_bytes = 0;
    } else {
        two_bytes = my_getnbr(tmp->token);
    }
    two_bytes = htobe16(two_bytes);
    write(fd, &two_bytes, sizeof(short));
}

static void write_direct(token_t *tmp, int fd, bool is_it_index)
{
    short two_bytes = 0;
    int four_bytes = 0;

    if (is_it_index) {
        if (tmp->prev->id == ID_LABEL) {
            two_bytes = 0;
        } else {
            two_bytes = my_getnbr(tmp->token);
        }
        two_bytes = htobe16(two_bytes);
        write(fd, &two_bytes, sizeof(short));
    } else {
        if (tmp->prev->id == ID_LABEL) {
            four_bytes = 0;
        } else {
            four_bytes = my_getnbr(tmp->token);
        }
        four_bytes = htobe32(four_bytes);
        write(fd, &four_bytes, sizeof(int));
    }
}

static int write_params(int fd, token_t *token, int index)
{
    char bytes = 0;
    bool is_it_index = is_index_type(op_tab[index].mnemonique);

    for (token_t *tmp = token; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == D_REG) {
            bytes = my_getnbr(tmp->token+1);
            write(fd, &bytes, sizeof(char));
        }
        if (tmp->type == D_IND) {
            write_indirect(tmp, fd);
        }
        if (tmp->type == D_DIR) {
            write_direct(tmp, fd, is_it_index);
        }
    }
    return EXIT_SUCCESS;
}

int write_instruction(int fd, token_t **array)
{
    int index = 0;

    for (size_t i = 0; array[i] != NULL; i++) {
        write_first_part(fd, array[i], &index);
        write_params(fd, array[i], index);
    }
    return EXIT_SUCCESS;
}