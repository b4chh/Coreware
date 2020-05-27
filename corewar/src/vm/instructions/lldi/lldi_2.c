/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** ldi_2.c
*/

#include "utils.h"
#include "vm.h"

int lldi_dir_reg_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = args[0].value;
    REG(champ, args[2].value) += REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int lldi_reg_reg_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = REG(champ, args[0].value);
    REG(champ, args[2].value) += REG(champ, args[1].value);
    return EXEC_SUCCESS;
}