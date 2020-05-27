/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init_prog_nbr.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int init_prog_nbr(param_t *this, vm_t *vm, char **av, int *idx)
{
    (void) vm;
    if (m_strcmp(av[*idx], "-n") != 0)
        return EXEC_SUCCESS;
    *idx += 1;
    CHECK_FALSE(*idx < len_tab(av))
    CHECK_FALSE(m_str_isnum(av[*idx]))
    this->prog_nbr = m_getnbr(av[*idx]);
    *idx += 1;
    return EXEC_SUCCESS;
}