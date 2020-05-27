/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_param.c
*/

#include "utils.h"
#include "vm.h"

param_t *create_param(int addr, int n, char *path)
{
    param_t *this = malloc(sizeof(param_t));

    CHECK_MALLOC(this)
    this->prog_nbr = n;
    this->addr = addr;
    this->path = path;
    return this;
}