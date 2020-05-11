/*
** EPITECH PROJECT, 2020
** write_on_memory
** File description:
** write_on_memory.c
*/

#include "corewar.h"
#include "struct.h"

unsigned char *write_data_on_mem(unsigned char *mem, int adr,
data_read_t *file)
{
    int a = 0;

    adr = adr % MEM_SIZE;
    for (size_t i = adr; a < file->head.prog_size; i++) {
        if (i >= MEM_SIZE)
            i = 0;
        mem[i] = file->data[a];
        a++;
    }
    return mem;
}