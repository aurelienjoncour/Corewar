/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** usage
*/

#include "corewar.h"

const char *usage_msg[] = {
    " [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...\n",
    "DESCRIPTION\n",
    "-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the",
    "round isn’t\nalready over) with the following format: 32 bytes/line\nin ",
    "hexadecimal (A0BCDEFE1DD3...)\n",
    "-n prog_number sets the next program’s number. By default, the first"
    "free number\nin the parameter order\n",
    "-a load_address sets the next program’s loading address. When no address",
    " is\nspecified, optimize the addresses so that the processes are as far",
    "\naway from each other as possible. The addresses are MEM_SIZE modulo.\n",
    NULL
};

int usage(char *binary, int status)
{
    my_putstr("USAGE\n");
    my_putstr(binary);
    for (size_t i = 0; usage_msg[i] != NULL; i++)
        my_putstr(usage_msg[i]);
    return status;
}