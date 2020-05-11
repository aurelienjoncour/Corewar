/*
** EPITECH PROJECT, 2020
** read_instruction
** File description:
** read_instruction
*/

#include "corewar.h"
#include "struct.h"

static void read_all_data(char *path, data_read_t *file)
{
    int fd = open(path, O_RDONLY);
    ssize_t nb_read = 0;

    nb_read = read(fd, &file->head, sizeof(header_t));
    file->head.prog_size = htobe32(file->head.prog_size);
    file->data = malloc(sizeof(unsigned char) * (file->head.prog_size + 1));
    nb_read = read(fd, file->data, file->head.prog_size);
    file->data[file->head.prog_size] = '\0';
    close(fd);
}

data_read_t read_file(char *path)
{
    data_read_t file;

    file.head.prog_size = 0;
    read_all_data(path, &file);
    return file;
}
