/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** store_nbr.c
*/

#include "utils.h"
#include "vm.h"

int m_pow(int n, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    return n * m_pow(n, p - 1);
}

int store_int(__u_char *mem, int idx)
{
    int i = 0;
    int res = 0;

    for (i = 0; i < (int) sizeof(int); i++) {
        res <<= TO_BITS(1);
        res |= mem[CIRCULAR((idx + i))];
    }
    return res;
}

short store_short(__u_char *mem, int idx)
{
    int i = 0;
    short res = 0;

    for (i = 0; i < (int) sizeof(short); i++) {
        res <<= TO_BITS(1);
        res |= mem[CIRCULAR((idx + i))];
    }
    return res;
}
