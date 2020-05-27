/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** ldi.c
*/

#include "utils.h"
#include "vm.h"

int ldi_ind_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) = (int) store_short(this->memory,
    IND(champ, args[0].value) % IDX_MOD);
    REG(champ, args[2].value) += args[1].value;
    return EXEC_SUCCESS;
}

int ldi_reg_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = REG(champ, args[0].value);
    REG(champ, args[2].value) += args[1].value;
    return EXEC_SUCCESS;
}

int ldi_dir_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = args[0].value;
    REG(champ, args[2].value) += args[1].value;
    return EXEC_SUCCESS;
}

int ldi_ind_reg_reg(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) = (int) store_short(this->memory,
    IND(champ, args[0].value) % IDX_MOD);
    REG(champ, args[2].value) += REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int ldi(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_LDI, NB_PATTERNS_LDI, args))
    (get_correct_pattern(PATTERN_LDI, NB_PATTERNS_LDI, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}