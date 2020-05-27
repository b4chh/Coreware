/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** zjmp.c
*/

#include "utils.h"
#include "vm.h"

int zjmp(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    if (champ->carry == true)
        champ->reg[PC_IDX] = IND(champ, args[0].value) % IDX_MOD;
    return EXEC_SUCCESS;
}