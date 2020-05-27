/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_param.c
*/

#include "utils.h"
#include "vm.h"

int destroy_param(param_t *this)
{
    free(this);
    return EXEC_SUCCESS;
}