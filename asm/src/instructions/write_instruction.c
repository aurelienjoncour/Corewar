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

static void write_indirect(token_t *tmp, int fd, token_t **array, int index)
{
    unsigned short two_bytes = 0;

    if (tmp->prev->id == ID_LABEL) {
        two_bytes = get_adress_label_short(tmp->token, array, index);
    } else {
        two_bytes = my_getnbr(tmp->token);
    }
    two_bytes = htobe16(two_bytes);
    write(fd, &two_bytes, sizeof(short));
}

static void write_direct(token_t *tmp, write_t *data, int index)
{
    unsigned short two_bytes = 0;
    unsigned int four_bytes = 0;

    if (data->is_it_index) {
        if (tmp->prev->id == ID_LABEL) {
            two_bytes = get_adress_label_short(tmp->token, data->array, index);
        } else {
            two_bytes = my_getnbr(tmp->token);
        }
        two_bytes = htobe16(two_bytes);
        write(data->fd, &two_bytes, sizeof(short));
    } else {
        if (tmp->prev->id == ID_LABEL) {
            four_bytes = get_adress_label(tmp->token, data->array, index);
        } else {
            four_bytes = my_getnbr(tmp->token);
        }
        four_bytes = htobe32(four_bytes);
        write(data->fd, &four_bytes, sizeof(int));
    }
}

static int write_params(write_t *data, int i)
{
    unsigned char bytes = 0;

    for (token_t *tmp = data->array[i]; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == D_REG) {
            bytes = my_getnbr(tmp->token+1);
            write(data->fd, &bytes, sizeof(char));
        }
        if (tmp->type == D_IND) {
            write_indirect(tmp, data->fd, data->array, i);
        }
        if (tmp->type == D_DIR) {
            write_direct(tmp, data, i);
        }
    }
    return EXIT_SUCCESS;
}

int write_instruction(int fd, token_t **array)
{
    write_t data = {0};

    data.fd = fd;
    data.array = array;
    for (size_t i = 0; array[i] != NULL; i++) {
        write_first_part(fd, array[i], &data.idx_mnemonique);
        data.is_it_index = is_index_type(
                            op_tab[data.idx_mnemonique].mnemonique);
        write_params(&data, i);
    }
    return EXIT_SUCCESS;
}