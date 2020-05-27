/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init_path.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int init_path(param_t *this, vm_t *vm, char **av, int *idx)
{
    (void) vm;
    CHECK_FALSE(*idx < len_tab(av))
    this->path = av[*idx];
    *idx += 1;
    return EXEC_SUCCESS;
}