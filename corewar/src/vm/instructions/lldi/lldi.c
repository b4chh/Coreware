/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lldi.c
*/

#include "utils.h"
#include "vm.h"

int lldi_ind_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) = (int) store_short(this->memory,
    IND(champ, args[0].value));
    REG(champ, args[2].value) += args[1].value;
    return EXEC_SUCCESS;
}

int lldi_reg_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = REG(champ, args[0].value);
    REG(champ, args[2].value) += args[1].value;
    return EXEC_SUCCESS;
}

int lldi_dir_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = args[0].value;
    REG(champ, args[2].value) += args[1].value;
    return EXEC_SUCCESS;
}

int lldi_ind_reg_reg(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) = (int) store_short(this->memory,
    IND(champ, args[0].value));
    REG(champ, args[2].value) += REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int lldi(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_LLDI, NB_PATTERNS_LLDI, args))
    (get_correct_pattern(PATTERN_LLDI, NB_PATTERNS_LLDI, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}