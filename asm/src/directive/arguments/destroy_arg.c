/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_arg.c
*/

#include "utils.h"
#include "asm.h"

int destroy_arg(args_t *this)
{
    free(this);
    return EXEC_SUCCESS;
}