/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lfork.c
*/

#include "utils.h"
#include "vm.h"

int lfork(vm_t *this, champion_t *champ, args_t *args)
{
    int n_addr = IND(champ, args[0].value);
    champion_t *child = duplicate_champion(champ);

    CHECK_NULL(child)
    child->pos = n_addr;
    child->reg[PC_IDX] = n_addr;
    list_push(&this->champions, child, child->header.prog_name);
    this->nb_champions++;
    return EXEC_SUCCESS;
}