/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_champions
*/

#include "corewar.h"

int init_champions(corewar_t *corewar)
{
    for (size_t i = 0; corewar->array[i].filepath != NULL && i < 4;i++) {
        corewar->array[i].head = malloc(sizeof(header_t));
        if (corewar->array[i].head == NULL)
            return EXIT_ERROR;
        if (read_file(&corewar->array[i]))
            return EXIT_ERROR;
        corewar->array[i].program = create_program(
        corewar->array[i].prog_number, corewar->array[i].load_address);
        if (corewar->array[i].program == NULL)
            return EXIT_ERROR;
    }
    if (!attribut_number(corewar->array))
        return EXIT_ERROR;
    attribut_memory(corewar->array);
    for (size_t i = 0; i < 4 && corewar->array[i].filepath != NULL; i++)
        write_data_on_mem(corewar, &corewar->array[i]);
    return EXIT_SUCCESS;
}