/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** trim_start_spaces.c
*/

#include "utils.h"
#include "asm/tokenizer.h"

char *trim_start_spaces(char *buffer)
{
    while (buffer[0] != '\0' && is_space(buffer[0]))
        buffer++;
    return buffer;
}