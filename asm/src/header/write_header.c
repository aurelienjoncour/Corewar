/*
** EPITECH PROJECT, 2020
** asm
** File description:
** write_header
*/

#include "corewar.h"

int write_header(int fd, header_t *header)
{
    header->magic = htobe32(COREWAR_EXEC_MAGIC);
    header->prog_size = 0;
    write(fd, header, sizeof(header_t));
    return EXIT_SUCCESS;
}