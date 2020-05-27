/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** write_memory.c
*/

#include "utils.h"
#include "vm.h"

int write_memory(__u_char *mem, int idx, int size, int value)
{
    int i = 0;

    if (idx < 0)
        idx += MEM_SIZE;
    for (i = 0; i < size; i++)
        mem[CIRCULAR(idx + i)] = value >> (i * TO_BITS(1));
    return EXEC_SUCCESS;
}