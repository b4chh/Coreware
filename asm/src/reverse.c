/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** reverse.c
*/

#include "utils.h"
#include "asm.h"

int reverse_int(int original)
{
    int byte1 = (original & 0x000000FF) >> 0;
    int byte2 = (original & 0x0000FF00) >> 8;
    int byte3 = (original & 0x00FF0000) >> 16;
    int byte4 = (original & 0xFF000000) >> 24;

    return (byte4 << 0) | (byte3 << 8) | (byte2 << 16) | (byte1 << 24);
}

short reverse_short(short original)
{
    short byte1 = (original & 0x00FF) >> 0;
    short byte2 = (original & 0xFF00) >> 8;

    return (byte2 << 0) | (byte1 << 8);
}