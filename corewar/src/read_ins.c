/*
** EPITECH PROJECT, 2020
** read_instruction
** File description:
** read_instruction
*/

#include "corewar.h"

static int read_all_data(int fd, champions_t *champion)
{
    ssize_t nb_read = 0;

    nb_read = read(fd, champion->head, sizeof(header_t));
    if (nb_read != sizeof(header_t))
        return EXIT_ERROR;
    champion->head->prog_size = htobe32(champion->head->prog_size);
    champion->data = malloc(sizeof(unsigned char) *
                            (champion->head->prog_size));
    if (champion->data == NULL)
        return EXIT_ERROR;
    nb_read = read(fd, champion->data, champion->head->prog_size);
    if (nb_read != champion->head->prog_size)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int read_file(champions_t *champion)
{
    int fd = open(champion->filepath, O_RDONLY);

    if (fd == -1)
        return EXIT_ERROR;
    read_all_data(fd, champion);
    close(fd);
    return EXIT_SUCCESS;
}
